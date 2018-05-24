/*
思路是:
root空，false
root->left, root->right都为空，返回root->val==sum
剩余所有情况可以简化为, leftsubSum || rightsubSum
https://leetcode.com/problems/path-sum/description/
*/
bool hasPathSum(TreeNode* root, int sum){
	if(!root)	return false;
	if(!root->left && !root->right){
		return (root->val==sum);
	}
	bool leftSubSum = hasPathSum(root->left, sum-root->val);
	bool rightSubSum = hasPathSum(root->right, sum-root->val);
	return leftSubSum || rightSubSum;
}

