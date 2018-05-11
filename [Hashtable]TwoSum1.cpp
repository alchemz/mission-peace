/**
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Two Sum
https://leetcode.com/problems/two-sum/description/

Hashtable O(n) time complexity
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map<int, int> mp;
        for(int i=0; i<(int)nums.size(); i++){
            mp[nums[i]]=i; //因为要返回的是index, 所以map to index
        }

        for(int i=0; i<(int)nums.size(); i++){
            if(mp.count(target - nums[i]) && mp[target-nums[i]] != i){
                return {i, mp[target-nums[i]]};
            }
        }

        return {};
    }
};