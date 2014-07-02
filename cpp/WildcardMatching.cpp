/**
*   Basic Idea: dp. Use two rows instead of allocating a two-dimension array
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int N1=0,N2=0;
        int i=0,j=0;
        N1=strlen(s);
		N2=strlen(p);
		int cnt=0;
		for(i=0;i<N2;i++)
			if(*(p+i)!='*')
				cnt++;
		if(cnt>N1)
			return false;
        int * dpUpRow=new int[N1+1];
        int * dpCurRow=new int[N1+1];
        int * tmp;
        for(j=0;j<(N1+1);j++)
        {
            dpUpRow[j]=0;
            dpCurRow[j]=0;
        }
        i=1;
        dpUpRow[0]=1;
		
        for(i=1;i<=N2;i++)
        {
			if(*(p+i-1)=='*'&&dpUpRow[0]==1)
				dpCurRow[0]=1;
			else
				dpCurRow[0]=0;
            for(j=1;j<=N1;j++)
            {
                if(*(p+i-1)=='?'||*(p+i-1)==*(s+j-1))
                    dpCurRow[j]=dpUpRow[j-1];
                else if(*(p+i-1)=='*')
                {	
                    if(dpUpRow[j]==1||dpCurRow[j-1]==1)
                        dpCurRow[j]=1;
                    else
                        dpCurRow[j]=0;
                }
                else
                    dpCurRow[j]=0;
            }
            tmp=dpUpRow;
            dpUpRow=dpCurRow;
            dpCurRow=tmp;
        }
        if(dpUpRow[N1]==1)
            return true;
        else
            return false;
    }
};
