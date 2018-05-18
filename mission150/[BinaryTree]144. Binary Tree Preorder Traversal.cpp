/*
preorder: root->left->right;
144. Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> dq;
        TreeNode *p = root;
        while(!dq.empty() || p!=NULL){
            if(p !=NULL){
                dq.push_back(p);
                res.push_back(p->val);     // Add before going to children
                p=p->left;
            }else{
                TreeNode *t = dq.back();dq.pop_back();   
                p = t->right;
            }
        }
        return res;
    }
};