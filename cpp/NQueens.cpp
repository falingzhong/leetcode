class Solution {
public:
    int N;
    vector<string> *pBoard;
    vector<vector<string>> res;

    vector<vector<string> > solveNQueens(int n) {
        N=n;
        vector<string> board(N,string(N,'.'));
        pBoard=&board;
        solve(0);
        return res;
    }

    void solve(int r)
    {
        if(r==N)
        {
            addSolution();
            return;
        }
        for(int c=0;c<N;c++)
        {
            if(canPlace(r,c))
            {
                (*pBoard)[r][c]='Q'; 
                solve(r+1);
                (*pBoard)[r][c]='.';
            }
        }
    }

    void addSolution(){
        res.push_back(*pBoard);
    }

    bool canPlace(int r,int c)
    {
        for(int i=0;i<r;i++)
        {
            if((*pBoard)[i][c]=='Q'||
               (c+r-i<N&&(*pBoard)[i][c+r-i]=='Q')||
               (c-(r-i)>=0&&(*pBoard)[i][c-(r-i)]=='Q'))
                return false;
        }
        return true;
    }
};
