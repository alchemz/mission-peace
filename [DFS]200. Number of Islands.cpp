class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans+=grid[i][j]-'0';
                dfs(grid, i, j, m, n);//吃掉联通的小岛
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0')//递归终止条件
            return;
        grid[i][j]='0';
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
    }
};

/*
i-上下边界
j-左边边界
m, n: row, col
深度搜索: 是0的话，就return;
不是0的话，标记为0, 然后上下左边dfs
用ans记录有多少个岛，是'1'的话, ans+='1'-'0', 加1

time: O(mn)

11110 
11010
11000
00000

00000 
00000
01000
00000
已访问的标记为0，相当于吃掉小岛

*/
