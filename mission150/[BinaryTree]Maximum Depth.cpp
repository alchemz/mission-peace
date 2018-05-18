/*
注意每次迭代计算subtree depth, 要加1
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        else if(!root->left) return 1+maxDepth(root->right);
        else if(!root->right)   return 1+maxDepth(root->left);
        else if(!root->left && !root->right)    return 1;
        else    return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};