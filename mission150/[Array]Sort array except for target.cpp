#include <bits/stdc++.h>
using namespace std;

void sortExceptTarget(vector<int> &nums, int target){
    int index=0;
    int n=nums.size();
    for(index; index<nums.size(); index++){
        if(nums[index]==target) break;
    }
    swap(nums[index],nums[n-1]);
    sort(nums.begin(), nums.end()-1);
    for(int i=n-1; i>index; i--){
        nums[i]=nums[i-1];
    }
    nums[index]=target;
}


// Driver code
int main()
{
	vector<int> arr = {10, 4, 11, 7, 6, 20 };
	int target=6;
	sortExceptTarget(arr, target);
	for(int i=0; i<arr.size(); i++)
	    cout<<arr[i]<<",";
}
//https://www.geeksforgeeks.org/sorting-array-elements-except-one/