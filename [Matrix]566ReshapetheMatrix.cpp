class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int idx=0;
        int m=nums.size();
        int n=nums[0].size();
        if(r*c != m*n) return nums;
        
        vector<int> all(m*n);
        for( int i=0; i<m; i++){
            for( int j=0; j<n; j++){
                all[idx++]=nums[i][j];
            }
        }
        
        int count=0;
        vector<vector<int>> ans(r, vector<int>(c));
        for( int i=0; i<r; i++){
            for( int j=0; j<c; j++){
                ans[i][j]=all[count++];
            }
        }
        return ans;
    }
};
