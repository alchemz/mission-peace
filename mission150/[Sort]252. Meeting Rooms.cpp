/*
道题给了我们一堆会议的时间，问我们能不能同时参见所有的会议，这实际上就是求区间是否有交集的问题
那么最简单暴力的方法就是每两个区间比较一下，看是否有overlap，有的话直接返回false就行了。
比较两个区间a和b是否有overlap，我们可以检测两种情况，如果a的起始位置大于等于b的起始位置，且此时a的起始位置小于b的结束位置，那么一定有overlap，
一种情况是a和b互换个位置，如果b的起始位置大于等于a的起始位置，且此时b的起始位置小于a的结束位置，那么一定有overlap
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
我们可以先给所有区间排个序，用起始时间的先后来排，然后我们从第二个区间开始，
如果开始时间早于前一个区间的结束时间，则说明会议时间有冲突，返回false，遍历完成后没有冲突，则返回true，参见代码如下：
*/
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};