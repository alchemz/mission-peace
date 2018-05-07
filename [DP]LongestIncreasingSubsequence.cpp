class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        vector<int> T(nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    T[i]= max(T[i], T[j]+1);
                }
            }
        }
        
        return *std::max_element(T.begin(), T.end());
        
    }
};