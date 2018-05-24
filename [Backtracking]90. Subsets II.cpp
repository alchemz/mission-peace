/*
注意：如果有重复的node, 一定要sort, 这样才能检测到
在for loop中，用if(i>idx && nums[i]==nums[i-1]) continue, 跳过重复的深度搜索
backtracking:

                        []        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 2] [1 2]  X   [1]  [2 2] [2] X  []
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(nums, 0, tmp, res);
        return res;
    }
    
    void subsetsWithDupHelper(vector<int>&nums, int idx, vector<int>&tmp,
                             vector<vector<int>>&res){
        res.push_back(tmp);
        for(size_t i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            subsetsWithDupHelper(nums, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};

//https://leetcode.com/problems/subsets-ii/description/