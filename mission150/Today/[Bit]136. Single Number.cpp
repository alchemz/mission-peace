/*
XOR will return 1 only on two different bits.
So if two numbers are the same.XOR will return 0, finally only one number left
A^A=0, A^B^A=B
*/
class Solution{
public:
	int singleNumber(vector<int>&nums){
		int res=nums[0];
		for(size_r i=0; i<nums.size(); i++){
			res = res^nums[i];
		}
		return res;
	}
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto element: nums){
            res = res^element;
        }
        return res;
    }
};