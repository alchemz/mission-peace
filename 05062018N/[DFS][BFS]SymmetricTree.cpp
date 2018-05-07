#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

bool CheckSymmetric(const TreeNode *left_sub, const TreeNode *right_sub){
	if(left_sub==NULL && right_sub==NULL){
		return true;
	}
	else if(left_sub !=NULL && right_sub !=NULL){
	    return left_sub->val== right_sub->val &&
		CheckSymmetric(left_sub->left, right_sub->right) &&
		CheckSymmetric(left_sub->right, right_sub->left);
	}
	return false;
}

bool IsSymmetric(const TreeNode *root){
	return root==NULL || CheckSymmetric(root->left, root->right);
}

int main(){
	TreeNode root(1);
	TreeNode t2(2);
	TreeNode t3(2);
	TreeNode t4(3);
	TreeNode t5(4);
	TreeNode t6(3);
	TreeNode t7(4);

	root.left = &t2;
	root.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t7;
	t3.right = &t6;

	if(IsSymmetric(&root))
		cout<<"Is symmetric";
	else
		cout<<"Not symmetric";

	return 0;
}
//time: O(n), space O(h)