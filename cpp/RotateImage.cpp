/**
 * Fist step: Upside down
 * Second: swap based on the diagnol
 */
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        int u,d,t;
        //swap left<->right
        for(int i=0;i<n;i++)
        {
            u=0;
            d=n-1;
            while(l<r)
            {
                t=matrix[u][i];
                matrix[u][i]=matrix[d][i];
                matrix[d][i]=t;
                u++;
                d--;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
    }
};

