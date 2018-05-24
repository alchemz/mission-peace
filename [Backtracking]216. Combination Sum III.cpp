/*
注意：进行深度搜索的时候 combinationSum3DFS(k-1, n-i, i+1, tmp, res);
结果是[]
combinationSum3DFS(k, n-i, i+1, tmp, res);
结果是[[1,2,4]]
所以这个k numbers在深度搜索的时候是不需要改变的。

注意: 满足solution的条件改成了if(n==0 && tmp.size()==k)


或者也可以换成combinationSum3DFS(k-1, n-i, i+1, tmp, res);
if(n==0 && k==0)
但是运行时间变长了。
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        combinationSum3DFS(k, n, 1, tmp, res);
        return res;
    }
    
    void combinationSum3DFS(int k, int n, int idx, vector<int>& tmp, vector<vector<int>>&res){
        if(n==0 && tmp.size()==k){
            res.push_back(tmp);
            return;
        }else{
            for(size_t i=idx; i<=9; i++){
                tmp.push_back(i);
                combinationSum3DFS(k, n-i, i+1, tmp, res);
                tmp.pop_back();
            }
        }
    }
};