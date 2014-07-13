#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,int> posMap; 
        vector<string> res;
        string tmp;
        
        for(int i=0;i<strs.size();i++)
        {
            tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(posMap.find(tmp)==posMap.end())
            {
                posMap[tmp]=i;
            }
            else
            {
                if(posMap[i]==-1)
                {
                    res.push_back(strs[i]);
                }
                else
                {
                    res.push_back(posMap[tmp]);
                    res.push_back(strs[i]);
                    posMap[tmp]=-1;
                }
            }
        }
        return res;
    }
};
