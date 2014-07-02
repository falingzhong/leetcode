#include<iostream>
using namespace std;

/**
*   Basic Ideal: swap positions to get array partially sorted.
*   The condition of while loop is difficult to get complete just once.
*/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n==0)
            return 1;
        for(int i=0;i<n;i++)
        {
            while((A[i]-1)!=i&&(A[i]-1)>=0&&(A[i]-1)<n&&A[A[i]-1]!=A[i])
            {
                swap(A,i,A[i]-1);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(A[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }

    void swap(int A[],int i,int j)
    {
        int t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
};


int main(){
    Solution sln;
    int A[]={1};
    int res=sln.firstMissingPositive(A,1);
    cout<<res<<endl;
    //for(int i=0;i<4;i++)
    //{
    //    cout<<A[i]<<" ";
    //}
    
    return 0;
}
