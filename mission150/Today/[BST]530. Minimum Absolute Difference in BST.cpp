/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
*/

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        long minDiff = INT_MAX;
        Helper(root, NULL, minDiff);
        return minDiff;
    }
private:
	void Helper(TreeNode *node, TreeNode*&prev, long& minDff){
		if(node->left){
			Helper(node->left, pre, minDiff);
		}
		if(pre !=NULL){
			minDiff=min(minDiff, (long)abs(node->val-pre->val));
		}
		pre = node;
		if(node->right){
			Helper(node->right, prev, minDiff);
		}
	}
};

/*
logic: inorder traverse the tree, store the node value in array,
compare adjacent element to get minDiff.

Time: O(n)
Space: O(n)
*/
class Solution{
public:
	int getMinimumDifference(TreeNode* root){
		vector<int> sorted;
		inorder(root, sorted);
		int minDiff= sorted.back();
		for(size_t i=1; i<sorted.size(); i++){
			minDiff=min(minDiff, sorted[i]-sorted[i-1]);
		}
		return minDiff;
	}
private:
	void inorder(TreeNode* root, vector<int>& sorted){
		if(root==NULL)	return;
		inorder(root->left, sorted);
		sorted.push_back(root->val);
		inorder(root->right, sorted);
	}
};