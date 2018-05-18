/*
convert sorted array to be height balanced BST
BST: 左边的树<root<右边的树

有序数组的中间是root节点，然后向左和右分成两个数组
再分别找左右节点中的根节点
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
    
    TreeNode* build(vector<int>& nums, int left, int right){
        if(left > right)    return NULL;
        int mid = (left + right)/2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = build(nums, left, mid-1);
        cur->right = build(nums, mid+1, right);
        return cur;
    }
};