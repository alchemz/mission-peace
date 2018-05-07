//http://www.cnblogs.com/grandyang/p/4510984.html
//https://leetcode.com/problems/3sum-closest/description/
#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int closet = nums[0]+nums[1]+nums[2];
    int diff = abs(target - closet);
    sort(nums.begin(), nums.end());
    for(int i=0; i<(int)nums.size()-2; i++){
        int left = i+1, right = nums.size()-1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            int newDiff = abs(target - sum);
            if(diff > newDiff){
                diff = newDiff;
                closet = sum;
            }
            if(sum < target) left++;
            else right--;
        }
    }
    return closet;
}
     
int main(){
  vector<int> test={-1, 2, 1, -4};
  int target =1;
  cout<<threeSumClosest(test, target);
  return 0;
}