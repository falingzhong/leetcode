#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int tMax=A[0];
        int tSum=A[0];
        for(int i=1;i<n;i++)
        {
            if(tSum+A[i]<A[i])
            {
                tSum=A[i];
            }
            else
            {
                tSum+=A[i];
            }
            if(tSum>tMax)
            {
                tMax=tSum;
            }
        }
        return tMax;
    }
};
