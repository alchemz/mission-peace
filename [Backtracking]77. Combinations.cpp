/*
 注意: 这里进行深度搜索的时候，不用改变n的值，因为题目是与值无关的。
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        combineDFS(n, k, 1, tmp, res);
        return res;
    }
    void combineDFS(int n, int k, int idx, vector<int>&tmp, vector<vector<int>>&res){
        if(tmp.size()==k){
            res.push_back(tmp);
        }
        for(size_t i=idx; i<=n; i++){
            tmp.push_back(i);
            combineDFS(n, k, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};