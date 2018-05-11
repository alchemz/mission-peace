/*
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
主要是考虑处理重复的状况
nums[k]==nums[k-1]
nums[j]==nums[i+1]
nums[j]==nums[j-1]

剪枝，减少运算量
nums[k]>0, 鉴于是已经排好序的数组，当第一个数已经大于0，后面不可能找到和为0的三个数
https://leetcode.com/problems/3sum/description/
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int k=0; k<nums.size(); k++){
            if(nums[k]>0) break;
            if(k>0 && nums[k]==nums[k-1]) continue;
            
            int target = -nums[k];
            int i=k+1, j=nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]==target){
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i<j && nums[j]==nums[i+1]) i++;
                    while(i<j && nums[j]==nums[j-1]) j--;
                    i++;
                    j--;
                }
                else if(nums[i]+nums[j]<target)
                    i++;
                else
                    j--;
            }
        }
        return res;
    }
};