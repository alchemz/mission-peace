/*
Given a binary tree, find its maximum depth
*/
#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class FindDepth{
public:
	int maxDepth(TreeNode* root){
		if(root==NULL){
			return 0;
		}else{
			int leftHeight=maxDepth(root->left);
			int rightHeight=maxDepth(root->right);

			return 1+max(leftHeight, rightHeight);
		}
	}
};

int main(){
	TreeNode root(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);

	root.left = &t2;
	root.right= &t3;
	t2.left = &t4;

	FindDepth f;
	cout<<f.maxDepth(&root)<<endl;
}