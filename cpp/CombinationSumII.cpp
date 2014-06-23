#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
*   Basic Idea: dfs
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> intermediate;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        dfs(num,0,intermediate,target);
        return res;
    }

    void dfs(vector<int> &num,int start,vector<int> &intermediate,int target)
    {
        if(target==0)
        {
            res.push_back(intermediate);
            return;
        }
        for(int i=start;i<num.size();i++)
        {
            if(i!=start&&num[i]==num[i-1])
                continue;
            if(num[i]>target)
                return;
            intermediate.push_back(num[i]);
            dfs(num,i+1,intermediate,target-num[i]);
            intermediate.pop_back();
        }
    }
};

int main(){
    Solution sln;
    vector<int> can(7);
    can[0]=10;
    can[1]=1;
    can[2]=2;
    can[3]=7;
    can[4]=6;
    can[5]=1;
    can[6]=5;
    sln.combinationSum2(can,8);


    return 0;
}

