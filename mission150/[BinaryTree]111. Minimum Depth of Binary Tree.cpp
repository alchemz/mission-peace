/*
*注意：和maxDepth, 一样，只是返回的是mindepth
*遵循的规律是: 
*!root, 0
*!left, 返回右+1
*!right, 返回左+1
*!left && !right, 返回1
*其他情况，返回1+min(minDepth(left), minDepth(right))
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        if(!root->left) return 1+minDepth(root->right);
        else if(!root->right)   return 1+minDepth(root->left);
        else if(!root->left && !root->right)    return 1;
        else    return 1+min(minDepth(root->left), minDepth(root->right));
    }
};