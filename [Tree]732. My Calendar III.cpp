class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++freq[start];
        --freq[end];
        int cnt = 0, mx = 0;
        for (auto f : freq) {
            cnt += f.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
    
private:
    map<int, int> freq;
};
http://www.cnblogs.com/grandyang/p/8005054.html
https://leetcode.com/problems/my-calendar-iii/description/