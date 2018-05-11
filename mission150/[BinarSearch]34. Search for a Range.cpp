/*
34. Search for a Range
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Recursive Binary Search
https://leetcode.com/problems/search-for-a-range/description/
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = search(nums, 0, nums.size()-1, target);
        if(idx==-1) return {-1, -1};
        int left = idx, right = idx;//以目标为轴，向两边扩散
        while(left > 0 && nums[left-1]==target) 
            --left;
        while(right<nums.size()-1 && nums[right+1]==target) 
            ++right;
        
        return {left, right};
    }
    
    int search(vector<int>&nums, int left, int right, int target){
        if(left > right) return -1;
        int mid = left + (right - left)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return search(nums, mid+1, right, target);
        else return search(nums, left, mid-1, target);
    }
};