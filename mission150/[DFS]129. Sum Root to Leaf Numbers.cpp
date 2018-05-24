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
给的树的遍历结果是按照preorder的顺序
所以可以按照preorder的顺序进行深度搜索
logic: 
1. 每次更新res=res*10 + node->val
2. 如果node->left, node->right都是NULL, 则直接返回curr node的值
3. 如果左右子不为空，则分别进行深度搜索，算各自的值相加
Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1

res = 4, node->val=>4
node->left=>9, node->right=>0
左边进行DFS, 5+9*10=95, 1+9*10=91
右边进行DFS, 0.
左边带上root, 495+491+40=1026
注意，当subtree进行DFS的时候，root的值也跟着同事迭代， 4*10, 40*10*10
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }
private:
    int sumNumbersHelper(TreeNode* node, int res){
        if(!node)   return 0;
        res = res*10 + node->val;//初始: res=0
        
        if(node->left==NULL && node->right==NULL){
            return res;
        }
        return sumNumbersHelper(node->left, res)
            + sumNumbersHelper(node->right, res);
    }
};