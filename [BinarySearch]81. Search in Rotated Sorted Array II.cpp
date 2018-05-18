//当有重复数字，会存在A[mid] = A[end]的情况
//A[mid] = A[end] != target时：搜寻A[start : end-1], end--
/*
1. 先判断左边还是右边是sorted, [mid]<[right]右边，[mid]>[right]左边
2. 在sorted区间，用binary search方法找mid
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target)   return true;
            if(nums[mid]<nums[right])
            {//right sorted
                if(nums[mid]< target && nums[right]>=target){ //mid小了
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            else if(nums[mid]>nums[right])
            {//left sorted
                if(nums[mid]> target && nums[left]<=target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            else{
                right--;
            }
        }
        return false;            
    } 
};