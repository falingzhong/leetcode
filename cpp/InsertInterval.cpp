#include<iostream>
#include<vector>

using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int N=intervals.size();
        if(N==0)
        {
            res.push_back(newInterval);
            return res;
        }
        int i=0;
        while(i<N&&newInterval.start>intervals[i].end)
        {
            res.push_back(intervals[i]);
            i++;
        }
        while(i<N&&newInterval.end>=intervals[i].start)
        {
            newInterval.start=min(newInterval.start,intervals[i].start);
            newInterval.end=max(newInterval.end,intervals[i].end);
            i++;
        }
        res.push_back(newInterval);
        while(i<N)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
