/*
滚动的球，一直走，直到墙才停下来。
1-墙体
0-通道
-1-已经访问过
*/
#include<bits/stdc++.h>
using namespace std;

class Maze {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) return true;
        int m = maze.size(), n = maze[0].size();//m-col, n-row
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(maze, dp, start[0], start[1], destination[0], destination[1]);
    }

    bool helper(vector<vector<int>>& maze, vector<vector<int>>& dp, int i, int j, int di, int dj) {
        if (i == di && j == dj) return true;
        if (dp[i][j] != -1) return dp[i][j];
        bool res = false;
        int m = maze.size(), n = maze[0].size();
        maze[i][j] = -1;
        for (auto dir : dirs) {
            int x = i, y = j;
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
                x += dir[0]; y += dir[1];
            }
            x -= dir[0]; y -= dir[1];
            if (maze[x][y] != -1) {
                res |= helper(maze, dp, x, y, di, dj);
            }
        }
        dp[i][j] = res;
        return res;
    }
};

int main(){
  vector<vector<int>> maze={{0,0,0,1,0},
                            {0,0,0,1,0},
                            {1,0,0,0,0},
                            {0,0,1,1,0},
                            {0,0,0,1,0}};
  // vector<vector<int>> maze={{0,0,0,1,0},
  //                           {0,0,0,1,0},
  //                           {1,0,0,0,0},
  //                           {0,0,1,1,0},
  //                           {0,0,0,1,0}};
  vector<int> start = {0,4};
  vector<int> end = {3,2};
  Maze m;
  bool res=m.hasPath(maze, start, end);
  if(res)
    cout<<"yes";
  else
    cout<<"no";
  
  return 0;
}
