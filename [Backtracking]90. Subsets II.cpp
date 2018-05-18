/*
https://leetcode.com/problems/subsets-ii/description/
 //======>注意跳过相同的数字，少一个branch
            if(i!=pos && nums[i]==nums[i-1])   continue;
*/
/*
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
https://leetcode.com/problems/subsets-ii/description/
用二叉树表达call stack会比较清晰
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty())    return {};
        vector<vector<int>> res;
        vector<int> out;
        //======>主语sort nums
        sort(nums.begin(), nums.end());//{1,2,1}
        subsetsWithDupHelper(nums, 0, out, res);
        return res;
    }
    
    void subsetsWithDupHelper(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &res){
        res.push_back(out);
        for(int i=pos; i<(int)nums.size(); i++){
            //======>注意跳过相同的数字，少一个branch
            if(i!=pos && nums[i]==nums[i-1])   continue;
            out.push_back(nums[i]);
            subsetsWithDupHelper(nums, i+1, out, res);
            out.pop_back();
        }
    }
};