/*
Same Tree
比较两个二叉树是否是一样的。
*/
#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p&&q) 
            return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
        else if(!q && !p) 
            return true;
        else 
            return false;
    }
};