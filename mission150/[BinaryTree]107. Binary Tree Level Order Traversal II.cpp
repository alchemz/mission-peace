/*
注意和正常的level order traversal是一样的，只是在最后rbegin, rend, revese vector 
https://leetcode.com/submissions/detail/154719755/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        build(root, 0, res);
        return vector<vector<int>> (res.rbegin(), res.rend());
    }
    
    void build(TreeNode *root, int level, vector<vector<int>> &res){
        if(root==NULL)  return;
        if(res.size()==level)   res.push_back({});
        res[level].push_back(root->val);
        if(root->left)  build(root->left, level+1, res);
        if(root->right) build(root->right, level+1, res);
    }
};