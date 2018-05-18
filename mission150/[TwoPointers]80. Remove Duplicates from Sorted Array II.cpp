/*
快慢指针+count计数器
当发现[cur]==[cur-1]:
a.count>=2, 跳过，cur++不计
b.count<2, count++, 记录[pre]=[cur], pre++, cur++.

其他情况[cur] != [cur-1],记录[pre]=[cur], pre++, cur++.
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)    return n;
        int pre=1, cur=1;
        int count=1;
        while(cur < n){
            if(nums[cur]==nums[cur-1]){
                if(count>=2){
                    cur++;
                    continue;
                }else{
                    count++;
                }
            }
            else{
                count=1;
            }
            nums[pre]=nums[cur];
            pre++;
            cur++;
        }
        return pre;
    }
};