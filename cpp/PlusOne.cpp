#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry=1;
        int size=digits.size();
        vector<int> res;
        vector<int> res2;
        int sum,rem;
        for(int i=size-1;i>=0;i--)
        {
            sum=digits[i]+carry;
            rem=sum%10;
            carry=sum/10;
            res.push_back(rem);
        }
        if(carry>0)
            res.push_back(carry);
        for(int i=res.size()-1;i>=0;i--)
        {
            res2.push_back(res[i]);
        }
        return res2;
    }
};
