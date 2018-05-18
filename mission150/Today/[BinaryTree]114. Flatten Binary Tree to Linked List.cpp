/*
把binary tree变成linked list
顺序是root->left->right, preorder
思路: binary tree preorder traversal, 然后再建链表
http://bangbingsyb.blogspot.com/2014/11/leetcode-flatten-binary-tree-to-linked.html

时间复杂度:
递归深度是O(logn)
vector的空间复杂度是O(n)
总的是O(n)
*/

void flatten(TreeNode *root){
	if(!root)	return;
	vector<TreeNode*> allNodes;
	preorder(root, allNodes);
	int n=allNodes.size();
	for(int i=0; i<n-1; i++){
		allNodes[i]->left = NULL;//因为题目要求是linked list, 所有左边分支都要移到右边
		allNodes[i]->right = allNodes[i+1];//根据preorder的顺序连起来
	}
	allNodes[n-1]->left=NULL;//最后的node连接为NULL
	allNodes[n-1]->right=NULL;
}

void preorder(TreeNode *root, vector<TreeNode*> &allNodes){
	if(!root)	return;
	allNodes.push_back(root);
	preorder(root->left, allNodes);
	preorder(root->right,allNodes);
}

//=====>递归构建
/*
如何将root、T(root->left)、T(root->right) flatten成一整个linked list？显而易见：

temp = root->right
root->right  = root->left
root->left = NULL
leftTail->right = temp
*/
void flatten(TreeNode *root) {
        TreeNode* rightTail = flattenBT(root);
    }
    
TreeNode* flattenBT(TreeNode* root) {
    if(!root) return NULL;
    TreeNode *leftTail = flattenBT(root->left);
    TreeNode *rightTail = flattenBT(root->right);
    if(root->left) {
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        leftTail->right = temp;
    }
    
    if(rightTail) return rightTail;
    if(leftTail) return leftTail;
    return root;
}