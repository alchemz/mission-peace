class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k<1|| nums.empty())	return 0;
        return getKth(nums.size()-k+1, nums, 0, nums.size()-1);
    }

    int getKth(int k, vector<int>&nums, int start, int end){
    	int pivot = nums[end];
    	int left = start;
    	int right = end;
    	while(true){
    		while(nums[left] < pivot && left < right){
    			left++;
    		}
    		while(nums[right]>=pivot && right > left){
    			right--;
    		}
    		if(left==right)	break;
    		swap(nums[left], nums[right]);
    	}
    	swap(nums[left], nums[end]);

    	if(k==left+1)	return pivot;
    	else if(k<left+1)	return getKth(k, nums, start, left-1);
    	else	return getKth(k, nums, left+1, end);
    }
};