/**
*   Basic Ideal: Search the most left, and then the most right. Both in Bisearch algorithm.
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if(n==0)
            return res;
        int left=searchRangeLeft(A,n,target);
        int right=searchRangeRight(A,n,target);
        res.push_back(left);
        res.push_back(right);
        return res;
    }

    int searchRangeLeft(int A[],int n,int target){
        int l=0;
        int r=n-1;
        int m;
        int res=n;
        
        while(l<=r)
        {
            m=(l+r)/2;
            if(A[m]==target){
                if(m<res)
                    res=m;
                r=m-1;
            }
            else if(target<A[m])
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        if(res==n)
            res=-1;
        return res;
    }

    int searchRangeRight(int A[],int n,int target){
        int l=0;
        int r=n-1;
        int m;
        int res=-1;
        
        while(l<=r)
        {
            m=(l+r)/2;
            if(A[m]==target){
                if(m>res)
                    res=m;
                l=m+1;
            }
            else if(target<A[m])
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return res;
    }
};
