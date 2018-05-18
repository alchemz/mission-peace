/*
postorder: left->right->root
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> dq;
        TreeNode *p = root;
        while(!dq.empty() || p!=NULL){
            if(p !=NULL){
                dq.push_back(p);
                res.insert(res.begin(), p->val);// Reverse the process of preorder
                p=p->right;                     // Reverse the process of preorder
            }else{
                TreeNode *t = dq.back();dq.pop_back();     
                p = t->left;                    // Reverse the process of preorder
            }
        }
        return res;
    }
};