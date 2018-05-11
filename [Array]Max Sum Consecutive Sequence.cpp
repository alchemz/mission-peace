//Max Sum Consecutive Subsequence
/*
curSum: max sum so far
endSum: max sum ending so far

traverse each element of the array
if(curSum < endSum)
	curSum = endSum
if(endSum < 0)
	endSum = 0

return curSum;
*/
#include <iostream>
using namespace std;

int maxSumConsecutiveSubsequence(vector<int> nums){
	int curSum = INT_MIN, endSum =0;
	for(int i=0; (int)i< nums.size(); i++){
		endSum = endSum + nums[i];
		if(curSum < endSum){
			curSum = endSum;
		}
		if(endSum < 0){
			endSum = 0;
		}
	}

	return curSum;
}