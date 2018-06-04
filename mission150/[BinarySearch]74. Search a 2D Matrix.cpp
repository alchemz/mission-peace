/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
找target是否在matrix中

time: O(logn)
space: O(1)
logic: binary search, 相当于一个sorted list.
从中间开始搜索，每次搜索范围减半。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back())  return false;
        int m = matrix.size(), n=matrix[0].size();
        int left=0, right = m*n-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(matrix[mid/n][mid%n]==target)    return true;
            else if(matrix[mid/n][mid%n]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        
        return false;
    }
};