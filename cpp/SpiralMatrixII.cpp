#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        if(n==0)
            return res;
        int u=0,l=0,r=n-1,d=n-1;
        int c=1;
        while(true)
        {
            for(int i=l;i<=r;i++)
            {
                res[u][i]=c++;
            }
            u++;
            if(u>d)
                break;
            for(int i=u;i<=d;i++)
            {
                res[i][r]=c++;
            }
            r--;
            if(r<l)
                break;
            for(int i=r;i>=l;i--)
            {
                res[d][i]=c++;
            }
            d--;
            if(d<u)
                break;
            for(int i=d;i>=u;i--)
            {
                res[i][l]=c++;
            }
            l++;
            if(l>r)
                break;
        }
        return res;
    }
};

int main(){
    //vector<int> t(10,0);
    //for(int i=0;i<t.size();i++)
    //{
    //    cout<<t[i]<<endl;
    //}
    return 0;
}

