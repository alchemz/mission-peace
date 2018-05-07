class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> level;

        subsetsHelper(res,level, nums, 0);
        return res;
    }
    
    void subsetsHelper(vector<vector<int>> &res,
                      vector<int> &level,
                      vector<int> &nums,
                      int pos){
        
        res.push_back(level);//空
        for(int i=pos; i<nums.size(); i++){
            level.push_back(nums[i]);
            subsetsHelper(res, level, nums, i+1);
            level.pop_back();
        }
    }
};