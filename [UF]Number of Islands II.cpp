#include<bits/stdc++.h>
using namespace std;

class AddLand {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m <= 0 || n <= 0) return res;
        vector<int> roots(m * n, -1);
        int cnt = 0;
        vector<vector<int> > dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto a : positions) {
            int id = n * a.first + a.second;
            roots[id] = id;
            ++cnt;
            for (auto d : dirs) {
                int x = a.first + d[0], y = a.second + d[1];
                int cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1) continue;
                int new_id = findRoots(roots, cur_id);
                if (id != new_id) {
                    roots[id] = new_id;
                    id = new_id;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int findRoots(vector<int> &roots, int id) {
        while (id != roots[id]) {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
};

int main(){
  AddLand a;
  vector<pair<int,int>> position={{0,0},{0,1},{1,2},{2,1}};
  vector<int> ans=a.numIslands2(3,3,position);
  for(unsigned i=0; i<ans.size(); i++){
    cout<<ans[i]<<", ";
  }
  return 0;
}

//https://www.cnblogs.com/grandyang/p/5190419.html
//https://leetcode.com/problems/number-of-islands-ii/description/