/*
有重复的数，注意if(visited[i]==true) continue;
if(visited[i]==false)
为了避免重复运算
if(i>0 && nums[i]==nums[i-1] && visited[i]==true) continue;
必须要加上&&visited[i]==true, 否则为[]
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        permuteUniqueDFS(nums, visited, tmp, res);
        return res;
    }
    
    void permuteUniqueDFS(vector<int>&nums, vector<bool>&visited, vector<int>&tmp,
                         vector<vector<int>>&res){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(size_t i=0; i<nums.size(); i++){
            if(visited[i]==true)    continue;
            if(visited[i]==false){
                if(i>0 && nums[i]==nums[i-1] && visited[i-1]==true) continue;
                tmp.push_back(nums[i]);
                visited[i]=true;
                permuteUniqueDFS(nums, visited, tmp, res);
                tmp.pop_back();
                visited[i]=false;
            }
        }
    }
};