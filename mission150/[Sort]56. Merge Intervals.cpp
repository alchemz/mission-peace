/*
1. 用两个数组分别记录starts, ends
2. 排序starts, ends
3. 根据比较starts[i+1], ends[i]得出是否连续

https://leetcode.com/problems/merge-intervals/description/
主要是比较，后starts[i+1], 和前ends[i]
starts[i+1] > ends[i], 不连续， 存进, j=i+1
starts[i+1] <= ends[i], 连续，查下一个，i++

i记录终止位置，j记录起始位置
特殊情况，当只剩下一个interval, i==n-1, 的时候，存进
*/
struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e){}
};

vector<Interval> merge(vector<Interval>& intervals){
    int n= intervals.size();
    vector<Interval> res;
    vector<int> starts, ends;

    for(int i=0; i<n; i++){
        starts.push_back(intervals[i].start);
        ends.push_back(intervals[i].end);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    for(int i=0, j=0; i<n; i++){
        if(starts[i+1]>ends[i]|| i==n-1){
            res.push_back(Interval(starts[j], ends[i]));
            j=i+1;
        }
    }
    return res;
}