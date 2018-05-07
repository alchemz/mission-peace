/*
Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys less than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- Both the left and right subtrees must also be binary search trees.

*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
private:
    bool isValidBST(TreeNode* root, int* min_val, int* max_val) {
        if (!root) return true;
        if ((min_val && root->val <= *min_val) 
          ||(max_val && root->val >= *max_val))
            return false;
        
        return isValidBST(root->left, min_val, &root->val)
            && isValidBST(root->right, &root->val, max_val);
    }
};
