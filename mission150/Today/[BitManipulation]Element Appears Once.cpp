/*
Find the element that appears once
Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2

Expected time complexity is O(n) and O(1) extra space.
*/

#include<bits/stdc++.h>
using namespace std;

//hashtable, worst case， O(n)
int getOnce(vector<int>& nums){
	unordered_map<int, int>mp;
	for(size_t i=0; i<nums.size(); i++){
	    mp[nums[i]]++;
	}
	for(auto element: nums){
	    if(mp[element]==1){
	        return element;
	    }
	}
}

int getOnce(vector<int>& nums){
	int ones=0, twos=0;
	int common_bit_mask;
	for(size_t i=0; i<nums.size(); i++){
	    //twos: 0, 3, 3, 1
		twos = twos|(ones&nums[i]);
		//ones: 3, 0, 2, 3
		ones = ones ^ nums[i];
		//common: 00, 00, 01, and 10
		common_bit_mask = ~(ones & twos);
		//remove common frome ones, 3,0,0,2
		ones &= common_bit_mask;
		//remove common bits from twos, 0,3,1,0
		twos &= common_bit_mask;
	}
	return ones;
}

int main(){
	vector<int>nums ={3,3,2,3};
	cout<<getOnce(nums);
	return 0;
}