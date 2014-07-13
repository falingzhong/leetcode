class Solution {
public:
    bool canJump(int A[], int n) {
        if(n==1)
            return true;
        int maxIdx=A[0];
        for(int i=0;i<n-1;i++)
        {
            if(maxIdx<i)
                return false;
            maxIdx=max(maxIdx,i+A[i]);
            if(maxIdx>=n-1)
                return true;
        }
        return false;
    }
};

