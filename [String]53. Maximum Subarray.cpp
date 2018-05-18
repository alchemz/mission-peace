/*
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Subarray比较特殊的是，数组是连续的, consecutive.
O(n)

https://leetcode.com/problems/maximum-subarray/description/
*/

int maxSubArray(vector<int>& nums) {
    int maxSum=INT_MIN, endSum=0;
    for(int i=0; i<(int)nums.size(); i++){
        endSum += nums[i];
        if(endSum > maxSum){
            maxSum = endSum;
        }
        if(endSum < 0){
            endSum = 0;
        }
    }
    
    return maxSum;
}