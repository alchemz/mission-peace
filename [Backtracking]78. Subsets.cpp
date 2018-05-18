/*
Input: nums = [1,2,3]
Output:
[
  [],
  [1],
  [1,2],
  [1,2,3],
  [1,3],
  [2]
  [2,3],
  [3]
]
https://leetcode.com/problems/subsets/description/
注意用二叉树表示call stack会比较清楚
              [ ]
         /      |    \
     [1]       [2]    [3]
    /  \        |
[1,2] [1,3]     [2,3]
/
[1,2,3]

*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> level;
        subsetsHelper(nums, 0, level, res);

        return res;
    }
    
    void subsetsHelper(vector<int>& nums, int pos, vector<int>& level, vector<vector<int>>& res){
        res.push_back(level);//level is empty now
        for(int i=pos; i<nums.size(); i++){
        	level.push_back(nums[i]);//存进每一层的数
        	subsetsHelper(nums, i+1, level, res);
        	level.pop_back();
        }
    }
};