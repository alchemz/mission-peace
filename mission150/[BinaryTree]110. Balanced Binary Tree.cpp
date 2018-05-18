/*
注意getDepth, 和maxDepth不一样
https://leetcode.com/problems/balanced-binary-tree/description/
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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)  return true;
        int leftSubDepth = getDepth(root->left);
        int rightSubDepth = getDepth(root->right);
        if(abs(leftSubDepth - rightSubDepth)>1) return false;
        return isBalanced(root->left)
            && isBalanced(root->right);
    }
    int getDepth(TreeNode *root){
        if(root==NULL)  return 0;
        return 1+max(getDepth(root->left), getDepth(root->right));
    }
};