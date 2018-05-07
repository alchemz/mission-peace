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
        if(!root) return {};
        vector<vector<int>> ans;
        vector<TreeNode*> curr,next;
        curr.push_back(root);
        while(!curr.empty()) {
            ans.push_back({});
            for(TreeNode* node : curr) {
                ans.back().push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            curr.swap(next);
            next.clear();
        }
        return ans;
    }
};

/*
sol:http://zxi.mytechroad.com/blog/leetcode/leetcode-102-binary-tree-level-order-traversal/
lc:https://leetcode.com/problems/binary-tree-level-order-traversal/description/

给定一颗二叉树，返回一个二维数组，使这个二维数组的每一个元素代表着二叉树的一层的元素.

思路：https://siddontang.gitbooks.io/leetcode-solution/content/tree/binary_tree_level_order_traversal.html

*/