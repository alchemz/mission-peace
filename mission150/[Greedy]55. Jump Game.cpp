/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Input: [2,3,1,1,4]
Output: true
*/

//动态规划
bool canJump(vector<int> &nums){
	vector<int> dp(nums.size(), 0);
	for(int i=1; i<nums.size(); i++){
		dp[i]=max(dp[i-1], nums[i-1])-1;
		if(dp[i]<0) return false;
	}
	return dp.back()>=0;
}

//贪心算法
bool canJump(vector<int> &nums){
	int n=nums.size(), cur=0;
	for(int i=0; i<n; i++){
		if(i>cur || cur>=n-1) break;
		cur = max(cur, i+nums[i]);//从当前位置可以去的最远
	}

	return cur>=n-1;
}