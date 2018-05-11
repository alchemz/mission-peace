/*
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
https://leetcode.com/problems/combination-sum/description/

类似题目:
Path Sum II 二叉树路径之和之二
Subsets II 子集合之二
Permutations 全排列
Permutations II 全排列之二
Combinations 组合项

需要另写一个递归函数
新加入三个变量
start记录当前的递归到的下标
out为一个解
res保存所有已经得到的解
每次调用新的递归函数时，此时的target要减去当前数组的的数
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }
    
    void combinationSumDFS(vector<int> &candidates, int target, int start, 
                           vector<int> &out, vector<vector<int>> &res){
        if(target <0) return;
        else if(target==0) res.push_back(out);
        else{
            for(int i=start; i<candidates.size(); i++){
                out.push_back(candidates[i]);
                combinationSumDFS(candidates, target-candidates[i], i, out, res);
                out.pop_back();
            }
        }
    }
};