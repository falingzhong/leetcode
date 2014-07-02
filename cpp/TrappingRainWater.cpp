/**
*   Basic Idea: scan twice,from left to right and from right to left.
*/
class Solution {
public:
    int trap(int A[], int n) {
        int *left=new int[n];
        int *right=new int[n];
        memset(left,0,sizeof(A));
        memset(right,0,sizeof(A));
        int lmax=0,rmax=0;
        for(int i=0;i<n;i++)
        {
            left[i]=lmax;
            if(A[i]>lmax)
                lmax=A[i];
        }

        for(int i=n-1;i>=0;i--)
        {
            right[i]=rmax;
            if(A[i]>rmax)
                rmax=A[i];
        }

        int res=0;
        for(int i=0;i<n;i++)
        {
            int h=min(left[i],right[i]);
            res+=(h>A[i]?h-A[i]:0);
        }
        return res;
    }
};
