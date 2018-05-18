/*
inorder traversal: left->root->right
https://leetcode.com/problems/binary-tree-inorder-traversal/description/

deque: first in, first out
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> dq;
        TreeNode *p = root;
        while(!dq.empty() || p!=NULL){
            if(p !=NULL){
                dq.push_back(p);
                p=p->left;
            }else{
                TreeNode *t = dq.back();dq.pop_back();
                res.push_back(t->val);//// Add after all left children
                p = t->right;
            }
        }
        return res;
    }
};