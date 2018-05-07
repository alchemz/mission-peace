#include <bits/stdc++.h>
using namespace std;

class Island {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                int cnt = 0;
                helper(grid, i, j, cnt, res);
            }
        }
        return res;
    }
    void helper(vector<vector<int>>& grid, int i, int j, int& cnt, int& res) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        res = max(res, ++cnt);
        grid[i][j] *= -1;
        for (auto dir : dirs) {
            helper(grid, i + dir[0], j + dir[1], cnt, res);
        }
    }
};

int main(){
  vector<vector<int>> grid={{0,0,1,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,0,0,0,1,1,1,0,0,0},
                            {0,1,1,0,1,0,0,0,0,0,0,0,0},
                            {0,1,0,0,1,1,0,0,1,0,1,0,0},
                            {0,1,0,0,1,1,0,0,1,1,1,0,0},
                            {0,0,0,0,0,0,0,0,0,0,1,0,0},
                            {0,0,0,0,0,0,0,1,1,1,0,0,0},
                            {0,0,0,0,0,0,0,1,1,0,0,0,0}};
  Island l;
  cout<<l.maxAreaOfIsland(grid);
  return 0;
}
//https://leetcode.com/problems/island-perimeter/description/
//http://www.cnblogs.com/grandyang/p/7712724.html