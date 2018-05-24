/*
找到，存储所有符合的path sum
注意: 用vector<int> out的时候，只是暂时用于储存每一个path, 不用reference.错误！
每个function call都用vector, 的话，cost, too high. 所以用reference
如果reference了，还要记得pop_back, 删掉存进的数

思路: 用DFS深度搜索每一个path
有三种情况
root为NULL，则没有path
root为leaf，且符合sum的值
root不是leaf node, 继续深度搜索left, right的值
*/
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum){
		vector<int> out;
		vector<vector<int>> allPaths;
		findPaths(root, sum, out, allPaths);
		return allPaths;

	}
private:
	void findPaths(TreeNode *root, int sum, vector<int> &out, vector<vector<int>> &allPaths){
		if(!root)	return;

		out.push_back(root->val);
		//leaf node
		if(!root->left && !root->right && root->val==sum){
			allPaths.push_back(out);
		}
		//not leaf node
		if(root->left){
			findPaths(root->left, sum-root->val, out, allPaths);
		}
		if(root->right){
			findPaths(root->right, sum-root->val, out, allPaths);
		}

		out.pop_back();
	}
};