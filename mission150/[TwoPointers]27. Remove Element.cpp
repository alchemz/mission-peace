/*
遍历数组，如果给定值不同，就把当前值覆盖
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(int j=0; j<(int)nums.size(); j++){
            if(nums[j]!=val){
                nums[i++]=nums[j];
            }
        }
        return i;
    }
};