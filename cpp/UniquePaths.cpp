#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int* row1=new int[n];
        int* row2=new int[n];

        for(int i=0;i<n;i++)
            row1[i]=1;
        for(int i=1;i<m;i++)
        {
            row2[0]=1;
            for(int j=1;j<n;j++)
            {
                row2[j]=row1[j]+row2[j-1];
            }
            row1=row2;
        }
        return row1[n-1];
    }
};

int main(){
    return 0;
}
