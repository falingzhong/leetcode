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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,intermediate,0,target);
        return res;
    }


    void dfs(vector<int> &candidates, vector<int> &intermediate,int start,int target)
    {
        if(target==0)
        {
            res.push_back(intermediate);
        }
        for(int i=start;i<candidates.size();i++)
        {
            if(candidates[i]<=target){
                intermediate.push_back(candidates[i]);
                dfs(candidates,intermediate,i,target-candidates[i]);
                intermediate.pop_back();
            }
            else
            {
                return;
            }
        }
    }
};

int main(){
    Solution sln;
    vector<int> can(4);
    can[0]=2;
    can[1]=3;
    can[2]=6;
    can[3]=7;
    sln.combinationSum(can,7);
    return 0;
}

