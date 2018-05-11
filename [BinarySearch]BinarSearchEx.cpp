/*
a recursive binary search function
O(logn)
https://www.geeksforgeeks.org/binary-search/
*/
#include<iostream>
#include<vector>
using namespace std;
//===============> recursive
int binarySearch(vector<int> nums, int l, int r, int target){
	if(r>=l){
		int mid = l + (r-l)/2;
		if(nums[mid]==target){
			return mid;
		}
		if(nums[mid] > target){
			return binarySearch(nums, l, mid-1, target);
		}
		return binarySearch(nums, mid+1, r, target);
	}
	return -1;
}

//================>iterative
int binarySearch(vector<int> nums, int l, int r, int target){
	while(l<=r){
		int mid = l+ (r-l)/2;
		if(nums[mid]==target)
			return mid;
		if(nums[mid]>target)
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}
int main(){
	vector<int> nums={1,2,3,4,5};
	int target=3;
	cout<<binarySearch(nums, 0, (int)nums.size()-1, target);
	return 0;
}