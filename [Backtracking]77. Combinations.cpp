class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> out;
        vector<vector<int>> res;
        combineHelper(n, k, 1, out, res);
        return res;
    }
    
    void combineHelper(int n, int k, int pos, vector<int> &out, vector<vector<int>>&res){
        //相对subsets, 只改变了一个条件，限制out.size()==k, 才存进
        if(out.size()==k)   res.push_back(out);
        for(int i=pos; i<=n; i++){
            out.push_back(i);
            combineHelper(n, k, i+1, out, res);
            out.pop_back();
        }
    }
};