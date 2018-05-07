#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    string res = "";
    priority_queue<pair<int, char>> q;
    unordered_map<char, int> m;
    for (char c : s) ++m[c];
    for (auto a : m) q.push({a.second, a.first});
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        res.append(t.first, t.second);
    }
    return res;
}

int main(){
  //test cases
  string test="Aabb";
  cout<<frequencySort(test);
  
  return 0;
}
//http://www.cnblogs.com/grandyang/p/6231504.html
//https://leetcode.com/problems/sort-characters-by-frequency/description/
