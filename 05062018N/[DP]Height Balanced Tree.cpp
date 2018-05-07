/*
Given a binary tree, determine if it is height-balanced.
https://leetcode.com/problems/balanced-binary-tree/description/
 	3
   / \
  9  20
    /  \
   15   7
*/
#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

//height of tree: the longest path from root to leaf
int height(TreeNode *node){
	if(!node){
		return 0;
	}

	return 1+max(height(node->left), height(node->right));
}

bool isBalanced(TreeNode *root){
	int lh;
	int rh;

	if(!root){
		return 1;
	}

	lh= height(root->left);
	rh= height(root->right);

	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
		return 1;
	}
	return 0;
}

int main(){
	TreeNode root(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
    TreeNode t5(5);
    
	root.left = &t2;
	root.right = &t3;
	t2.left = &t4;
    t4.left = &t5;
    
	if(isBalanced(&root))
		cout<<"Balanced"<<endl;
	else 
		cout<<"Not balanced"<<endl;

	return 0;
}