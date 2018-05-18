/*
要求生成所有的unique BST，类似combination/permutation的题目，可以递归构造。
1. 根节点可以任取lower ~ upper (例如lower  = 1, upper = n)，假如取定为i。
2. 则left subtree由lower ~ i-1组成，right subtree由i+1 ~ upper组成
生成所有可能的left/right subtree leftTree = genBST(lower, i-1), rightTree = genBST(i+1,upper)
3. 对于生成的left subtree/right subtree， 添上节点i, 作为root, 生成一个新的数，
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)    return {};
        return genBST(1, n);
    }
    
    vector<TreeNode*> genBST(int lower, int upper){
        vector<TreeNode*> res;
        if(lower>upper){
            res.push_back(NULL);
            return res;
        }
        
        for(int i=lower; i<=upper; i++){
            vector<TreeNode*> leftTree = genBST(lower, i-1);//左边的数用lower~i-1来造
            vector<TreeNode*> rightTree = genBST(i+1, upper);//右边的数用i+1 ~ upper来造
            for(int j=0; j<leftTree.size(); j++){
                for(int k=0; k<rightTree.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};