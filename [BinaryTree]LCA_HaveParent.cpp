struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
}

int GetHeight(TreeNode *p){
	int height=0;
	while(p){
		height++;
		p=p->parent;
	}
	return height;
}

TreeNode *LCA(TreeNode *p, TreeNode *q){
	int h1=GetHeight(p);
	int h2=GetHeight(q);

	if(h1>h2){
		swap(h1, h2);
		swap(p, q);
	}

	int diff=h2-h1;
	for(int h=0; h<diff; h++){ //move q to the same level of p
		q= q->parent;
	}
	while(p&&q){
		if(p==q) return p;
		p=p->parent;
		q=q->parent;
	}

	return NULL;
	
}
//https://articles.leetcode.com/lowest-common-ancestor-of-a-binary-tree-part-ii/
//https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-tree-set-2-using-parent-pointer/