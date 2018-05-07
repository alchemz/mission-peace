#include<bits/stdc++.h>
using namespace std;

// int leastInterval(vector<char>& tasks, int n) {
//     int res = 0, cycle = n + 1;
//     unordered_map<char, int> m;
//     priority_queue<int> q;
//     for (char c : tasks) ++m[c];
//     for (auto a : m) q.push(a.second);
//     while (!q.empty()) {
//         int cnt = 0;
//         vector<int> t;
//         for (int i = 0; i < cycle; ++i) {
//             if (!q.empty()) {
//                 t.push_back(q.top()); q.pop();
//                 ++cnt;
//             }
//         }
//         for (int d : t) {
//             if (--d > 0) q.push(d);
//         }
//         res += q.empty() ? cnt : cycle;
//     }
//     return res;
// }
    
int leastInterval(vector<char>& tasks, int n) {
    int mx = 0, mxCnt = 0;
    vector<int> cnt(26, 0);        
    for (char task : tasks) {
        ++cnt[task - 'A'];//char to int
        if (mx == cnt[task - 'A']) {
            ++mxCnt;
        } 
        else if (mx < cnt[task - 'A']) {
            mx = cnt[task - 'A'];
            mxCnt = 1;
        }
    }
    int partCnt = mx - 1;
    int partLen = n - (mxCnt - 1);
    int emptySlots = partCnt * partLen;
    int taskLeft = tasks.size() - mx * mxCnt;
    int idles = max(0, emptySlots - taskLeft);
    return tasks.size() + idles;
}
     
int main(){
  vector<char> tasks={'A','A','A','B','B','E'};
  cout<<leastInterval(tasks, 2);
  return 0;
}
/*
http://www.cnblogs.com/grandyang/p/7098764.html
先处理高频，再处理低频
*/