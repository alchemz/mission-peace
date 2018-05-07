// Runtime: 32 ms
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                ans = max(ans, area(grid, j, i, w, h));
        return ans;
    }
private:
    int area(vector<vector<int>>& grid, int x, int y, int w, int h) {
        if (x < 0 || y < 0 || x >= w || y >= h || grid[y][x] == 0) return 0;
        
        grid[y][x] = 0;
        
        return area(grid, x - 1, y, w, h) 
             + area(grid, x + 1, y, w, h)
             + area(grid, x, y - 1, w, h)
             + area(grid, x, y + 1, w, h)
             + 1;            
    }
};

/*
sol: http://zxi.mytechroad.com/blog/graph/leetcode-695-max-area-of-island/
lc:https://leetcode.com/problems/max-area-of-island/description/

由二维数组中的0,1代表海洋和陆地，找到最大面积的岛屿
输入:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 输出: 6
*/