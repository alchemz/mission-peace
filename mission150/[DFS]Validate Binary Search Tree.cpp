/*
Solution 1:
时间复杂度: O(n), 因为要validate every node.
空间复杂度: O(h), 递归的深度，即这个树的最大高度

注意，valid BST要求 left sub tree < root < right sub tree.
左边所有的node都必须在 (lower_bound, root->val)的区间
右边所有的node都必须在(root->val, upper_bound)的区间
防止溢出可以用LONG_MIN, LONG_MAX

相当于root->val > lower_bound, root->val<upper_bound;
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)  return true;
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBSTHelper(TreeNode* root, long lower_bound, long upper_bound){
        if(!root)   return true;
        
        if(root->val <=lower_bound || root->val >= upper_bound){
            return false;
        }
        return isValidBSTHelper(root->left, lower_bound, root->val)
            && isValidBSTHelper(root->right, root->val, upper_bound);
    }
};

/*
Solution 2:
用中序遍历，这样存储来的数组是sorted, 比较cur, pre，看是否符合left<root<right
Time: O(n)
Space: O(h)
*/