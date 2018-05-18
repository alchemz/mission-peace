/*
注意BST里面的每一个左边的node都要比root小，同期右边
注意：防止溢出，所以用long
https://leetcode.com/problems/validate-binary-search-tree/description/
终止条件为当前节点为空，或者左右节点不符合二叉树定义
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
    bool isValidBST(TreeNode* root) {
        //用long是为了防止溢出
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBSTHelper(TreeNode* root, long lower_bound, long upper_bound){
        if(!root)   return true;
        if(root->val <= lower_bound || root->val >= upper_bound)  return false;
        
        return isValidBSTHelper(root->left, lower_bound, root->val)
            && isValidBSTHelper(root->right, root->val, upper_bound);
    }
};