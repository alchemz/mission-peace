class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) {
            return {};
        }
   
        vector<vector<int>> res;
        vector<int> level;
        sort(nums.begin(), nums.end());
        subsetsHelper(res, nums, level, 0);
        return res;
    }
    void subsetsHelper(vector<vector<int>> &res, 
                       vector<int> &nums, 
                       vector<int> &level, 
                       int pos){
        res.push_back(level);
        for(int i=pos; i<(int)nums.size(); i++){
            level.push_back(nums[i]);
            subsetsHelper(res, nums, level, i+1);
            level.pop_back();
            while(i+1 < nums.size() && nums[i]==nums[i+1]) {
                i++;
            }

        }
    }
};