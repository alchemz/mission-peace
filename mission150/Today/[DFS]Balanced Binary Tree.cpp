/*
Height Balanced Binary tre: 要求left sub tree, right subtree的高度差值不大于1
input: [3,9,20,NULL, NULL, 15, 7]
   3
   / \
  9  20
    /  \
   15   7
output: true
*/

/*
solution 1
time complexity: O(nlogn), O(n)+2*O(n/2)+4*O(n/4)+....最坏情况是O(nlogn), 右边最后一层不是balanced
space complexity: O(h)
注意在计算depth的时候是取1+max(depth(node->left), depth(node->right))
这样可以保证比较长的subtree也符合balanced的条件
*/
class Solution{
public:
	bool isBalanced(TreeNode* root){
		if(!root)	return true;
		if(abs(depth(root->left) - depth(root->right))>1){
			return false;
		}
		return isBalanced(root->left)
			&& isBalanced(root->right);
	}

	int depth(TreeNode* node){
		if(!node)	return 0;
		return 1+ max(depth(node->left),depth(node->right));
	}	
};

/*
solution 2
可以优化成O(n), 在计算height的时候，就判断是不是balanced.
注意每次的balanced的状态要用& reference
anything non-zeor is true.
*/
class Solution{
public:
	bool isBalanced(TreeNode* root){
        if(!root)   return true;
        bool balanced = true;
        depth(root, &balanced);
        return balanced;
    }
private:
    int depth(TreeNode *root, bool *balanced){
        if(!root)   return 0;
        int left_depth = depth(root->left, balanced);
       // if(!balanced)   return -1;
        int right_depth = depth(root->right, balanced);
        //if(!balanced)   return -1;
        if(abs(left_depth - right_depth)>1){
            *balanced = false;
            return -1; //exit from current block of function
        }
        return max(left_depth, right_depth) +1;
    }
};