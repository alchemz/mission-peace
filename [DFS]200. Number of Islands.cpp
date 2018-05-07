class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //1. corner case
        if(grid.empty()) return 0;
        
        //2. count numlands with dfs
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans+=grid[i][j]-'0';
                dfs(grid, i, j, m, n);
            }
        }
        return ans;
    }

private:
    //check neighbours
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0')
            return;
        grid[i][j]='0';
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
    }
};

/*
lc: https://leetcode.com/problems/number-of-islands/description/
sol: http://zxi.mytechroad.com/blog/searching/leetcode-200-number-of-islands/
*/