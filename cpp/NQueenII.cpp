#include<iostream>
#include<math.h>
#include<cstdlib>
#include<string.h>
using namespace std;
class Solution {
public:
    int res;
    int N;
    int* row;
    int* col;
    
    int totalNQueens(int n) {
        N=n;
        res=0;
        row=new int[N];
        col=new int[N];
        memset(row,0,N*4);
        memset(col,0,N*4);
        dfs(0);
        return res;
    }
    void dfs(int r){
        int j;
        if(r==N)
        {
            res++;
            return;
        }
        for(int i=0;i<N;i++)
        {
            if(col[i]==0)
            {
                for(j=0;j<r;j++)
                {
                    if(abs(j-r)==abs(i-row[j]))
                    {
                        break;
                    }
                }
                if(j==r)
                {
                    row[r]=i;
                    col[i]=1;
                    dfs(r+1);
                    col[i]=0;
                    row[r]=0;
                }
            }
        }
    }
};
int main(){
    Solution sln;
    int res=sln.totalNQueens(4);
    cout<<res<<endl;
    return 0;
}
