class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) {
                    dfs(rooms, i + 1, j, 1);
                    dfs(rooms, i - 1, j, 1);
                    dfs(rooms, i, j + 1, 1);
                    dfs(rooms, i, j - 1, 1);
                }
            }
        }
    }
    void dfs(vector<vector<int>> &rooms, int i, int j, int val) {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[i].size()) return;
        if (rooms[i][j] > val) {
            rooms[i][j] = val;
            dfs(rooms, i + 1, j, val + 1);
            dfs(rooms, i - 1, j, val + 1);
            dfs(rooms, i, j + 1, val + 1);
            dfs(rooms, i, j - 1, val + 1);
        }
    }
};
// http://www.cnblogs.com/grandyang/p/5285868.html
// https://leetcode.com/problems/walls-and-gates/description/