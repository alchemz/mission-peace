class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN, endSum=0;
        for(int i=0; i<(int)nums.size(); i++){
            endSum += nums[i];
            if(endSum > maxSum){
                maxSum = endSum;
            }
            if(endSum < 0){
                endSum = 0;
            }
        }
        
        return maxSum;
    }
};