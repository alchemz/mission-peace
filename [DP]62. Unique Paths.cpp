/*
求机器人从start, 到finish能由多少种路径
只能向右边走，或者向下走。

用动态规划，因为当前位置的路径数[i][j]=[i-1][j]+[i][j-1];
https://leetcode.com/problems/unique-paths/description/
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0){
                    f[i][j]=1;
                }else{
                    f[i][j]=f[i-1][j]+f[i][j-1];
                }
            }
        }
        return f[m-1][n-1];
    }
};