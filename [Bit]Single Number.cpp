/*
由于数字在计算机是以二进制存储的，每位上都是0或1，如果我们把两个相同的数字异或，0与0异或是0,1与1异或也是0，那么我们会得到0。根据这个特点，我们把数组中所有的数字都异或起来，则每对相同的数字都会得0，然后最后剩下来的数字就是那个只有1次的数字。
https://leetcode.com/problems/single-number/description/
http://www.cnblogs.com/grandyang/p/4130577.html
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) res ^= num;
        return res;
    }
};

// Problem 2
// a = [1, 1, 5, 5, 2, 2, 6, 4, 4, 3, 3]
// a = [1, 1, 6, 5, 5, 2, 2, 4, 4, 3, 3]
int findOne(vector<int>& nums){
    int left=0, right=nums.size()-1;
    while(left<=right){
        int mid=left + (right-left)/2;//10/2
        if(mid%2==1){
            if(nums[mid]==nums[mid-1]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }else{
            if(nums[mid]==nums[mid-1]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
    }
    return right;
}

/*
odd,
nums[mid]==nums[mid-1], drop left，left=mid+1
else, drop right，right=mid-1;
even
nums[mid]==nums[mid-1], right=mid+1
else, left=mid+1

left=0, right=10, mid=5, 
odd, nums[mid]==nums[mid-1], left=6
left=6, right=10, mid=8, 
even, nums[mid]=nums[mid-1], right=7
left=6, right=7, mid=6
even, nums[mid]!=nums[mid-1], left=7
left=7, right=7, mid=7, 
odd, nums[mid]!=nums[mid-1], right=6

*/
