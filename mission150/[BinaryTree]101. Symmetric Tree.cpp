bool isSymmetric(TreeNode *root){
	if(root==NULL)		return true;
	return isSymmetricHelper(root->left, root->right);
}

bool isSymmetricHelper(TreeNode *leftSub, TreeNode *rightSub){
	if(leftSub==NULL)		return rightSub==NULL;
	if(rightSub==NULL)		return leftSub==NULL;
	if(leftSub->val != rightSub->val)		return false;
	return isSymmetricHelper(leftSub->left, rightSub->right)
			&& isSymmetricHelper(leftSub->right, rightSub->left);

}