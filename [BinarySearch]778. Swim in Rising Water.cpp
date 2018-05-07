#include <bits/stdc++.h>
using namespace std;

bool canReach(vector<vector<int>>& grid, int t, int curr, int target, unordered_set<int>& visited)
{
    int m = grid.size(), n = m? grid[0].size(): 0, i = curr / n, j = curr % n;
    if(curr == m * n - 1)return true;
    visited.insert(curr);
    pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int k = 0; k < 4; ++k)
    {
        int x = i + dirs[k].first, y = j + dirs[k].second;
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] <= t && visited.find(x * n + y) == visited.end())
        {
            if(canReach(grid, t, x * n + y, target, visited))return true;
        }
    }
    return false;
}

int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size(), n = m? grid[0].size(): 0, lo = n && m? grid[0][0]: 0, hi = m * n - 1;
    while(lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        unordered_set<int> visited;
        if(canReach(grid, mid, 0, m * n - 1, visited))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
    
int main(){
  vector<vector<int>> grid={{0,2},{1,3}};
  //{{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
  cout<<swimInWater(grid);
  return 0;
}

//http://hehejun.blogspot.com/2018/02/leetcodeswim-in-rising-water.html
//https://leetcode.com/problems/swim-in-rising-water/description/
/*
给定长宽为N的二维方阵grid，记grid[x][y] = z表示当时刻t >= z时，x, y可达。

在grid上的移动可以瞬间完成，求从0, 0出发，到达N - 1, N - 1的最短时刻。
二分法
*/