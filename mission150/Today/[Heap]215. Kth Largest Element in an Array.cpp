/*
Input: [3,2,1,5,6,4] and k = 2
Output: 5
*/
//quicksort
/*
核心思想是每次都要先找一个中枢点Pivot，然后遍历其他所有的数字，
像这道题从大往小排的话，就把小于中枢点的数字放到左半边，把大于中枢点的放在右半边，
这样中枢点是整个数组中第几大的数字就确定了

求出中枢点的位置，如果正好是k-1，那么直接返回该位置上的数字；
如果大于k-1，说明要求的数字在左半部分，更新右边界，再求新的中枢点位置；
反之则更新右半部分，求中枢点的位置；不得不说，这个思路真的是巧妙啊～
*/
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
//best: O(nlong), worst: O(n^2), average: O(nlogn)

//priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};