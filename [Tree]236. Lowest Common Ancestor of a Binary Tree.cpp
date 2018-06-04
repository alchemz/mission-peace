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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return NULL;
        //如果p, q就是root
        if(root->val == p->val || root->val == q->val)
            return root;
        
        //如果left_lca, right_lca都返回non-NULL, 就是root是lca
        TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_lca= lowestCommonAncestor(root->right,p, q);
        if(left_lca&&right_lca) return root;
        
        //找出left_lca或者right_lca是lca
        return (left_lca!=NULL)? left_lca:right_lca;
    }
};

//time: O(n), a traversal has been done