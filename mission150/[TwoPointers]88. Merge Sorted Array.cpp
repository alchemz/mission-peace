/*
从后往前，把较大的数赋值给m+n-1
https://leetcode.com/problems/merge-sorted-array/description/
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        int j = n-1;
        int k = m-1;

            while(j>=0 && k>=0){
                //注意，是从后往前赋值，所以取大的数
                if(nums2[j]>nums1[k])
                    nums1[i--]=nums2[j--];
                else
                    nums1[i--]=nums1[k--];
            }
            //数组二还有剩余
            while(j>=0){
                nums1[i--]=nums2[j--];
            }
    }
};