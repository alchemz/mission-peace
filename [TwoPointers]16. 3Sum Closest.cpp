/*
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
https://leetcode.com/problems/3sum-closest/description/
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestDiff = INT_MAX;
        for(int i=0; i< nums.size()-2; i++){
            int left=i+1, right=nums.size()-1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                int curDiff = sum - target;
                
                if(abs(curDiff)<abs(closestDiff)){
                    closestDiff = curDiff;
                }
                
                if(sum < target)
                    left++;
                else
                    right--;
            }
        }
        return closestDiff+target;
    }
};