/*
注意当j > i+1 && nums[j]==nums[j-1],的时候可以skip, 因为是同样的数。
time complexity: O(n^3)
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
https://leetcode.com/problems/4sum/description/
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for(int i=0; i<(int)nums.size()-3; i++){
            for(int j=i+1; j< (int) nums.size()-2; j++){
                if(j > i+1 && nums[j]==nums[j-1]) continue;//skip
                int left = j+1, right=nums.size()-1;
                while(left < right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target){
                        res.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};