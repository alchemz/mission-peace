//time: O(n)
//space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int, int> indies;
        for(int i=0; i<n; i++)
            indies[nums[i]]=i;
        
        for(int i=0; i<n; i++){
            int left = target - nums[i];
            if(indies.count(left)&& indies[left]!=i)
                return {i, indies[left]};
        }
        
        return {};
    }
};
//https://leetcode.com/problems/two-sum/description/
