#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &i1,const Interval &i2)
{
    return i1.start<i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<int> startEdge,endEdge;
        vector<Interval> res;
        int N;
        if(intervals.size()==0)
            return res;
        sort(intervals.begin(),intervals.end(),cmp);
        res.push_back(intervals[0]);
        N=1;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start>res[N-1].end)
            {
                res.push_back(intervals[i]);
                N++;
            }else
            {
                res[N-1].end=max(res[N-1].end,intervals[i].end);
            }
        }
        return res;
    }
};

int main(){
    
    vector<Interval> inputs;
    Interval i1(1,3);
    Interval i2(2,6);
    Interval i3(8,10);
    Interval i4(15,18);

    inputs.push_back(i1);
    inputs.push_back(i2);
    inputs.push_back(i3);
    inputs.push_back(i4);

    Solution sln;

    vector<Interval> res=sln.merge(inputs);
    
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
    return 0;

}
