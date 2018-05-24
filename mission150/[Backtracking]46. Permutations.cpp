/*
permutation是元素的排列组合，所以注意标注已经用过的, continue;
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        permuteDFS(nums, visited, tmp, res);
        return res;
    }
    
    void permuteDFS(vector<int>& nums, vector<bool> &visited, vector<int>& tmp, vector<vector<int>>&res){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
        }
        for(size_t i=0; i<nums.size(); i++){
            if(visited[i]) continue;
            else{
                tmp.push_back(nums[i]);
                visited[i]=true;//num[i]已经用过了
                permuteDFS(nums, visited, tmp, res);
                tmp.pop_back();
                visited[i]=false;//tmp pop出num[i],记录为没有用过。
            }
        }
    }
};