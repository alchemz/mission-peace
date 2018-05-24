/*时间复杂度 O(n) 空间复杂度 O(m*h)
m是sol的个数，h是树的深度

可以用递归的方式，每次方程，注意更新sum-node->val, 
当sum==0&&node->next==NULL的时候，记录sol
*/
/*
注意符合深度搜索的条件是，当前的node不是Leaf
存进res的条件是, 是leaf node, 且当前值是和sum减剩下的值一样的。

不加reference的话，时间复杂度会变成O(n^2)
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        pathSumHelper(root, sum, tmp, res);
        return res;
    }
    
    void pathSumHelper(TreeNode* node, int sum, vector<int>&tmp, vector<vector<int>>&res){
        if(!node){
            return;
        }
        
        tmp.push_back(node->val);
        //如果leftsubtree, rightsubtree都没有node, 说明是leaf node
        if(!node->left && !node->right && node->val==sum){
            res.push_back(tmp);
        }
        //如果leftsubTree有node, not leaf node
        if(node->left){
            pathSumHelper(node->left, sum-node->val, tmp, res);
        }
        //如果rightsubTree有node, not leaf node
        if(node->right){
            pathSumHelper(node->right, sum-node->val, tmp, res);
        }
        tmp.pop_back();
    }
};