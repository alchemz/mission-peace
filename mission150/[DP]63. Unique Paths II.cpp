/*
注意第0行， 第0列的特殊情况，有obstacle的时候break
其他状况有obstacle, continue

https://leetcode.com/problems/unique-paths-ii/description/
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0]==1)   break;//会影响到本行后面的路径
            f[i][0]=1;
        }
        for(int j=0; j<n; j++){
            if(obstacleGrid[0][j]==1)   break;//会影响到本列后面的路径
            f[0][j]=1;
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1)   continue; //只会影响当前位置
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        
        return f[m-1][n-1];
    }
};