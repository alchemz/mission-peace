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
     vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        
        std::sort(intervals.begin(), intervals.end(), 
                  [](const Interval& a, const Interval& b){
                        return a.start < b.start;
                    });
        
        vector<Interval> ans;        
        for (const auto& interval : intervals) {
            if (ans.empty() || interval.start > ans.back().end) {
                ans.push_back(interval);
            } else {
                ans.back().end = max(ans.back().end, interval.end);
            }
        }
        
        return ans;
    }
};
/*
sol:http://zxi.mytechroad.com/blog/geometry/leetcode-56-merge-intervals/
lc: https://leetcode.com/problems/merge-intervals/description/
将有重合的区间合并
输入：[1,3],[2,6],[8,10],[15,18]
输出：[1,6],[8,10],[15,18]

思路：
1.将所有区间排序
2.检测是否有重合
3.合并
*/