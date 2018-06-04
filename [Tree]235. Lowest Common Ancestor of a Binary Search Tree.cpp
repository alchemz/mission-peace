/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// //递归 time:O(h), space:O(h) 
// //requires O(h) extra space in function call stack for recursive function calls, h is height of tree
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root)   return NULL;
//         if(root->val > p->val && root->val > q->val){
//             return lowestCommonAncestor(root->left, p, q);
//         }
//         else if(root->val <p->val && root->val<q->val){
//             return lowestCommonAncestor(root->right, p, q);
//         }
//         else return root;
//     }
// };
//非递归 time:O(h), space: O(1)
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        while(true){
            if(root->val > p->val && root->val > q->val)
                root=root->left;
            else if(root->val <p->val && root->val<q->val)
                root=root->right;
            else
                break;
        }
        return root;
    }
};