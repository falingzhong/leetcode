#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        if(numbers.size()==2)
            return numbers;
        map<int,int> pos; 
        map<int,int>::iterator it=pos.end();

        int comp;
        for(int i=0;i<numbers.size();i++){
            comp=target-numbers[i];
            it=pos.find(comp);
            if(it==pos.end()){
                pos.insert(pair<int,int>(numbers[i],i));
                //cout<<numbers[i]<<" "<<i<<endl;
            }else{
                ret.push_back(it->second+1);
                ret.push_back(i+1);
                return ret;
            }
        }
        return ret;
    }
};

void main(){
    Solution sln=Solution();
    vector<int> input;
    input.push_back(2);
    input.push_back(7);
    input.push_back(11);
    input.push_back(15);
    vector<int> res=sln.twoSum(input,9);
    cout<<res[0]<<" "<<res[1]<<endl;
}

