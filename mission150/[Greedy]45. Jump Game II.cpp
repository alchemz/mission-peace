/*
Jump Game II
贪心
Each element in the array represents your maximum jump length at that position.
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

int jump(vector<int> &nums){
	//两个变量cur和pre分别来保存当前的能到达的最远位置和之前能到达的最远位置
	int res=0, n=nums.size(), i=0, cur=0;
	while(cur < n-1){
		res++;
		int pre=cur;
		for(; i<=pre; i++){
			cur = max(cur, i+nums[i]);//当前的能到达的最远位置
		}
	}

	return res;
}