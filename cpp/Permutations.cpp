#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(),num.end());
        bool *visits=new bool[num.size()];
        memset(visits,0,sizeof(bool)*num.size());
        vector<int> intermediate;
        dfs(num,intermediate,visits);
        return res;
    }

    void dfs(vector<int>& num,vector<int> &intermediate, bool* visits)
    {
        if(intermediate.size()==num.size())
            res.push_back(intermediate);
        for(int i=0;i<num.size();i++)
        {
            if(!visits[i])
            {
                visits[i]=true;
                intermediate.push_back(num[i]);
                dfs(num,intermediate,visits);
                intermediate.pop_back();
                visits[i]=false;
            }
        }
    }
};

int main(){
    Solution sln;
    vector<int> num(2);
    num[0]=0;
    num[1]=1;
    vector<vector<int>> res=sln.permute(num);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
