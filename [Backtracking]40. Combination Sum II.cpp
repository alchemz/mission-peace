/*
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Combination II中，数字不可以重复使用
Each number in candidates may only be used once in the combination.
https://leetcode.com/problems/combination-sum-ii/description/
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        combinationSum2DFS(candidates, target, 0, out, res);
        return res;
    }
    void combinationSum2DFS(vector<int> &candidates, int target, int start,
                           vector<int>&out, vector<vector<int>>&res){
        if(target<0) return;
        else if(target==0) res.push_back(out);
        else{
            for(int i=start; i<candidates.size(); i++){
                if(i>start && candidates[i]==candidates[i-1]) continue;//防止res出现重复项
                out.push_back(candidates[i]);
                combinationSum2DFS(candidates, target-candidates[i], i+1, out, res);//i+1, 防止重复用一个数
                out.pop_back();
            }
        }
    }
};