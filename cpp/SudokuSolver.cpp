#include<iostream>
#include<vector>
using namespace std;

/**
*   Basic Ideal: use three matrix to record if the value is used.
*   Borrow the ideal of dfs.
*/
class Solution {
public:
    int rowMaps[9][9];
    int colMaps[9][9];
    int subMaps[9][9];
    
    void solveSudoku(vector<vector<char> > &board) {
        init(board);
        bool res=solveSudoku(0,0,board);
    }

    void printSudoku(vector<vector<char>> &board){
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void init(vector<vector<char>> &bd){
        memset(rowMaps,0,sizeof(rowMaps));
        memset(colMaps,0,sizeof(colMaps));
        memset(subMaps,0,sizeof(subMaps));
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                char ch=bd[r][c];
                if(ch!='.')
                {
                    int num=ch-'0'-1;
                    rowMaps[r][num]=1;
                    colMaps[c][num]=1;
                    int idx=(r/3)*3+c/3;
                    subMaps[idx][num]=1;
                }
            }
        }
    }

    bool validate(int r,int c,int v){
        if(rowMaps[r][v]==1)
            return false;
        if(colMaps[c][v]==1)
            return false;
        int idx=(r/3)*3+c/3;
        if(subMaps[idx][v]==1)
            return false;
        return true;
    }

    void setMaps(int r,int c,int pos,int v)
    {
        rowMaps[r][pos]=v;
        colMaps[c][pos]=v;
        int idx=(r/3)*3+c/3;
        subMaps[idx][pos]=v;
    }


    bool solveSudoku(int row,int col,vector<vector<char>> &bd)
    {
        if(row==9)
        {
            //printSudoku(bd);
            return true;
        }
        char c=bd[row][col];
        int nexRow,nexCol;
        if(c!='.')
        {
            nexCol=col+1;
            nexRow=row;
            if(nexCol==9)
            {
                nexRow=row+1;
                nexCol=0;
            }
            return solveSudoku(nexRow,nexCol,bd);
        }
        else
        {
            bool isValid=false;
            for(int i=0;i<9;i++)
            {
                isValid=validate(row,col,i);
                
                if(!isValid)
                    continue;
                setMaps(row,col,i,1);
                bd[row][col]=(char)('0'+i+1);
                nexCol=col+1;
                nexRow=row;
                if(nexCol==9)
                {
                    nexRow=row+1;
                    nexCol=0;
                }
                isValid=solveSudoku(nexRow,nexCol,bd);
                if(isValid)
                    return true;
                setMaps(row,col,i,0);
                bd[row][col]='.';
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board;
    for(int i=0;i<9;i++)
    {
        vector<char> row(9);
        board.push_back(row);
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            board[i][j]='.';
        }
    }
    board[0][0]='5';
    board[0][1]='3';
    board[0][4]='7';
    
    board[1][0]='6';
    board[1][3]='1';
    board[1][4]='9';
    board[1][5]='5';

    board[2][1]='9';
    board[2][2]='8';
    board[2][7]='6';

    board[3][0]='8';
    board[3][4]='6';
    board[3][8]='3';
    
    board[4][0]='4';
    board[4][3]='8';
    board[4][5]='3';
    board[4][8]='1';

    board[5][0]='7';
    board[5][4]='2';
    board[5][8]='6';

    board[6][1]='6';
    board[6][6]='2';
    board[6][7]='8';
    
    board[7][3]='4';
    board[7][4]='1';
    board[7][5]='9';
    board[7][8]='5';

    board[8][4]='8';
    board[8][7]='7';
    board[8][8]='9';

    Solution sln;
    sln.solveSudoku(board);
    
}
