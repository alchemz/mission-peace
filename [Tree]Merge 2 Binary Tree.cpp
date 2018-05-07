/*
Merge 2 Binary Tree
given 2 binary tree, and put one of them over the other. the nodes could be overlapped.
如果有重合的node, 将两个node的值相加
*/

#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
		if(!t1)	return t2;
		else if(!t2) return t1;
		else{
			TreeNode *tmp= new TreeNode(t1->val+t2->val);
			tmp->left = mergeTrees(t1->left, t2->left);
			tmp->right = mergeTrees(t1->right, t2->right);
			return tmp;		
		}
	}
};

int main(){
	TreeNode a1(1);
	TreeNode a2(3);
	TreeNode a3(2);
	TreeNode a4(5);

	TreeNode b1(2);
	TreeNode b2(1);
	TreeNode b3(3);
	TreeNode b4(4);
	TreeNode b5(7);

	a1.left = &a2;
	a1.right = &a3;
	a2.left =&a4;

	b1.left =&b2;
	b1.right=&b3;
	b2.right=&b4;
	b3.right=&b5;

	Solution S;
	S.mergeTrees(&a1, &a2);

	return 0;
}