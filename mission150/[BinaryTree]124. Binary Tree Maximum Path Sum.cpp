//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
四种情况:
1. Node only
2. L-sub + Node
3. R-sub + Node
4. L-sub + Node + R-sub
因为路径的开始和结尾可以是任意位置，那么就需要对当前节点的左边，右边都进行深度搜索，并且与0比较
如果比0小，是负数则不要加
记录最大的路径是 res = max(res, left+right+node->val)
结果是max(left, right)+node->val

记录和返回结果是不一样的，要注意
*/
//   int maxPathSum(TreeNode* root) {
//         int res = INT_MIN;
//         helper(root, res);
//         return res;
//     }
    
//     int helper(TreeNode *node, int&res){
//         if(!node)   return 0;
//         int left = max(helper(node->left, res), 0); 
//         int right =max(helper(node->right,res), 0);
//         res = max(res, left+right+node->val);
//         return max(left, right)+node->val;
//     }
class Solution {
public:
    int maxPathSum(TreeNode *root){
        int maxAcrossRoot = INT_MIN;
        int maxEndbyRoot = getMax(root, maxAcrossRoot);
        return max(maxAcrossRoot, maxEndbyRoot);
    }
    
    int getMax(TreeNode *node, int &maxAcrossRoot){
        if(node==NULL)  return 0;
        //计算最大4. L-sub + Node + R-sub
        int left = getMax(node->left, maxAcrossRoot);
        int right = getMax(node->right, maxAcrossRoot);
        int l_root_r = node->val;
        if(left>0)
            l_root_r += left;
        if(right>0)
            l_root_r += right;
        maxAcrossRoot = max(maxAcrossRoot, l_root_r);
        
        return max(node->val, max(left+node->val, right+node->val));
        //先比较左边+root, 右边+root哪个大
        //然后再比较和root本身比哪个大
        //返回值是1，2，3其中一个。1. Node only， 2. L-sub + Node， 3. R-sub + Node
    }
};