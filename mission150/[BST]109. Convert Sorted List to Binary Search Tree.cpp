/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
二分法，用快慢指针找到中间节点，作为root
*/
/*
注意终止条件是:
a. tmp=tail
b. tmp->next = tail

注意当head=tail,的时候，返回NULL
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
    	return sortedListToBST( head, NULL );
    }
private:   
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
    	if(head == tail)  return NULL;	
    	ListNode *mid = head, *temp = head;
    	while( temp != tail && temp->next != tail )    // 寻找中间节点
    	{
    		mid = mid->next;
    		temp = temp->next->next;
    	}
    	TreeNode *root = new TreeNode(mid->val);
    	root->left = sortedListToBST(head, mid);
    	root->right = sortedListToBST(mid->next, tail);
    	return root;
    }
};