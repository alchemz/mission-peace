/*
先对角，再上下
注意第一次旋转，i<n-1, j<n-i //对称轴不用旋转
https://leetcode.com/problems/rotate-image/description/
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i; j++){
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
    }
};