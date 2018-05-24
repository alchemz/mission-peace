/*
Input:[1,2,3]
Output:[[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
logic:
res先记录一个空[], 然后进入for loop, tmp存进第一个数，
进入深度循环，res存进[1]，res存进[1,2], res存进[1,2,3]
类似一个tree的structure, 每个节点存在两种情况，选和不选，leftsubtree表示选，rightsubtree表示不选
最终所有的节点是所有的答案。

                        []        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []    

*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        subsetsHelper(nums, 0, tmp, res);
        return res;
    }
    
    void subsetsHelper(vector<int>&nums, int idx, vector<int>&tmp, vector<vector<int>>& res){
        res.push_back(tmp);
        for(size_t i=idx; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            subsetsHelper(nums, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};