/*
1. 建立一个levelOrderHelper function, 用到三个变量，root, level, res
2. root代表当前扫描到的node, level代表递归到的层数，res代表返回的二维数组
3. 注意当level递归到对应层数的时候，建立一个空层，往里面加数字
4. 先检查左边的树，再坚持右边的树，分别进入下一层递归
https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderHelper(root, 0, res);
        return res;
    }
    
    void levelOrderHelper(TreeNode *root, int level, vector<vector<int>> &res){
        if(root==NULL)   return;
        //当level递归到上一层的个数，我们新建一个空层，继续往里面加数字
        if(res.size()== level)  res.push_back({});
        res[level].push_back(root->val);
        if(root->left)  levelOrderHelper(root->left, level+1, res);
        if(root->right) levelOrderHelper(root->right, level+1, res);
    }
};