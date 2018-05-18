/*
35. Search Insert Position
Input: [1,3,5,6], 5
Output: 2

找的到，就返回所在index;
找不到，返回插入位置

https://leetcode.com/problems/search-insert-position/description/
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};

//=======================>优化时间复杂度, binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        if(nums.back()< target) return n;
        
        int left=0, right = n-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        return right;//n
    }
};