class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};//row: 4, col:2
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                vector<pair<int, int>> v;
                helper(grid, i, j, i, j, v);
                res.insert(v);
            }
        }
        return res.size();
    }
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<pair<int, int>>& v) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        grid[i][j] *= -1;
        v.push_back({i - x0, j - y0});//记录这个形状
        for (auto dir : dirs) {
            helper(grid, x0, y0, i + dir[0], j + dir[1], v);//d0{0,-1}, d1{-1,0}
        }
    }
};

/*
单个岛屿的位置判断，(-1,0), (1,0), (0,-1),(0,1) 上下左右
{0,-1},{-1,0},{0,1},{1,0}, 左，下，右，上，逆时针
将相对坐标存进数组v中，再把整个数组放进集合set中,
helper(grid, x0, y0, i + dir[0], j + dir[1], v); 就知道是不是同样形状的岛屿
*/
