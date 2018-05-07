/*
Invert Binary Tree
左边的leaf和右边的leaf交换
*/
#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	TreeNode* invertTree(TreeNode *root){
		if(!root) return NULL;
		else{
			TreeNode *tmp = root->left;
			root->left= invertTree(root->right);
			root->right = invertTree(tmp);
			return root;
		}

	}
};

int main(){
	TreeNode root(4);
	TreeNode t2(2);
	TreeNode t3(7);
	TreeNode t4(1);
	TreeNode t5(3);
	TreeNode t6(6);
	TreeNode t7(9);

	root.left=&t2;
	root.right=&t3;
	t2.left=&t4;
	t2.right=&t5;
	t3.left=&t6;
	t3.right=&t7;

	Solution S;
	S.invertTree(&root);
	cout<<"inverted"<<endl;
	return 0;
}
