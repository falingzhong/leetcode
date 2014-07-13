class Solution {
public:
    int jump(int A[], int n) {
        int cur=0;
        int last=0;
        int i;
        int step=0;
        for(i=0;i<n;i++)
        {
            if(i>last)
            {
                step++;
                last=cur; 
            }
            cur=max(cur,i+A[i]);
        }
        return step;
    }
};
