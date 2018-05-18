/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   https://leetcode.com/problems/unique-binary-search-trees/description/
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1,0);
        res[0]=1;
        res[1]=1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                res[i] += res[j]*res[i-j-1];
            }
        }
        
        return res[n];
    }
};