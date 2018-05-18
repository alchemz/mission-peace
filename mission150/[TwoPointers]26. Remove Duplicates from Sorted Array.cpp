/*
slow记录当前存储的不重复数字的位置
fast记录当前扫描到的位置
注意更新nums时用，nums[slow]=nums[fast]
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)    return n;
        int slow=1, fast=1;
        while(fast<n){
            if(nums[fast]==nums[fast-1]){
                fast++;
                continue;
            }
            nums[slow]=nums[fast];
            slow++;
            fast++;
        }
        return slow;
    }
};