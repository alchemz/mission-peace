/*
logic: 
如果哈希表中没有num-1这个数，直接开始while loop, 找连续子序列个数
用count++计数，cur++来找下一个数, longest来记录最长的子序列长度
时间复杂度: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> f(nums.begin(), nums.end());
        int longest=0;
        for(auto num: nums){
            if(f.count(num-1)==false){
                int count=1;
                int cur = num;
                while(f.count(cur+1)){
                    count++;
                    cur++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};