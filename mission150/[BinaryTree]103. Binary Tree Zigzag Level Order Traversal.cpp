/*
注意和一般的level order traversal是一样的，
芝士在zigzagorder function里面，把奇数行1, 3, 5,...reverse
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
    void build(TreeNode* root, vector<vector<int>>& res, int level) {
        if(!root)  return;
        if(level==res.size())   res.push_back(vector<int>());
        res[level].push_back(root->val);
        if(root->left)  build(root->left, res, level+1);
        if(root->right) build(root->right, res,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        build(root,res, 0);
        for(int i=1; i<res.size(); i+=2){
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }

};