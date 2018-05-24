/*
注意；
为了保证unique solution, 如果用if(candidates[i]==candidates[i-1]) continue;
结果是[[1,2,5],[1,7],[2,6]]
如果用if(i>idx && candidates[i]==candidates[i-1]) continue;
结果是[[1,1,6],[1,2,5],[1,7],[2,6]]
因为第一个if condition, 忽略了[1,1,6],数组中原本有相同元素的可能性
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationSum2DFS(candidates, target, 0, tmp, res);      
        return res;
    }
    
    void combinationSum2DFS(vector<int>& candidates, int target, int idx, 
                           vector<int>& tmp, vector<vector<int>>& res){
        if(target<0){
            return;
        }
        else if(target==0){
            res.push_back(tmp);
            return;
        }else{
            for(size_t i=idx; i<candidates.size(); i++){
                if(i>idx && candidates[i]==candidates[i-1]) continue;
                tmp.push_back(candidates[i]);
                combinationSum2DFS(candidates, target-candidates[i], i+1, tmp, res);
                tmp.pop_back();
            }
        }
    }
    
};