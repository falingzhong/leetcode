class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid[0][0]==1)
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int * row1=new int[n];
        int * row2=new int[n];
        row1[0]=obstacleGrid[0][0]==1?0:1;
        int obs=0;//indicate the first row is obscaled
        for(int i=1;i<n;i++)
        {
            if(row1[i-1]==0||obstacleGrid[0][i]==1)
                row1[i]=0;
            else
                row1[i]=1;
        }
        for(int i=1;i<m;i++)
        {
            row2[0]=obstacleGrid[i][0]==1?0:1;
            if(obstacleGrid[i][0]==1||obs==1)
            {
                obs=1;
                row2[0]=0;
            }

            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    row2[j]=0;
                else
                {
                    row2[j]=row2[j-1]+row1[j];
                }
            }
            row1=row2;
        }
        return row1[n-1];
    }
};

