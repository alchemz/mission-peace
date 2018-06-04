struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode *sortedArrayToBST(vector<int>&nums){
	return build(nums, 0, nums.size()-1);
}

TreeNode *build(vector<int>&nums, int left, int right){
	if(left>right)	return null;
	int mid= (left+right)/2;
	TreeNode* cur= new TreeNode(nums[mid]);
	cur->left = build(nums, left, mid-1);
	cur->right= build(nums, mid+1, right); //mid本身是root
	return cur;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    while(true){
        if(root->val > p->val && root->val > q->val)
            root=root->left; //舍弃右边的树
        else if(root->val <p->val && root->val<q->val)
            root=root->right;//舍弃左边的树
        else
            break;
    }
    return root;
}

/*
先建树, sorted array to binary search tree
然后根据LCA定义，找到LCA
*/