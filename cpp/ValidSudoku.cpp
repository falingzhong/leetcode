/**
*   Basic Ideal: notice line 23. It is very likely to get out of range.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rowMap[9];
        int colMaps[9][9];
        int subMaps[9][9];
        char c;
        int iv;
        int subIdx;
        memset(colMaps,0,sizeof(colMaps));
        memset(subMaps,0,sizeof(subMaps));
        for(int i=0;i<9;i++)
        {
            memset(rowMap,0,sizeof(rowMap));
            for(int j=0;j<9;j++)
            {
                c=board[i][j];
                if(c=='.')
                    continue;
                iv='c'-'0'-1;
                if(rowMap[iv]==1)
                    return false;
                rowMap[iv]=1;
                if(colMaps[j][iv]==1)
                    return false;
                colMaps[j][iv]=1;
                subIdx=(i/3)*3+j/3;
                if(subMaps[subIdx][iv]==1)
                    return false;
                subMaps[subIdx][iv]=1;
            }
        }
        return true;
    }
};
