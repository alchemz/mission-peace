class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size(), cur = 0;
        while (cur < n && intervals[cur].end < newInterval.start) {
            res.push_back(intervals[cur++]);
        }
        while (cur < n && intervals[cur].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[cur].start);
            newInterval.end = max(newInterval.end, intervals[cur].end);
            ++cur;
        }
        res.push_back(newInterval);
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};
http://www.cnblogs.com/grandyang/p/4367569.html
https://leetcode.com/problems/insert-interval/description/