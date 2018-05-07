int maxSumSubsequence(vector<int>& nums) {
    vector<int> T(nums.size(), 0);
    for(int i=0; i<nums.size(); i++){
        T[i]=nums[i];
    }
    
    for(int i=1; i<nums.size();i++){
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i]){
                T[i]= max(T[i], T[j]+nums[i]);
            }
        }
    }
    
    return *std::max_element(T.begin(), T.end());
}