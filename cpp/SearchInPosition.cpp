/**
*   Basic Ideal: BiSearch.
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n==0)
            return 0;
        int left=0;
        int right=n-1;
        int mid;
        while(left<=right)
        {
            if(target<=A[left])
                return left;
            if(target>A[right])
                return right+1;
            mid=(left+right)/2;
            if(target==A[mid])
                return mid;
            else if(target<A[mid])
                right=mid-1;
            else
                left=mid+1;
        }
    }
};
