/*
http://www.cnblogs.com/grandyang/p/4481576.html
http://www.cnblogs.com/grandyang/p/4515925.html
http://www.cnblogs.com/grandyang/p/4130379.html
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target){
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  for(unsigned int k=0; k<nums.size(); k++){
    if(k>0 && nums[k] == nums[k-1]) continue; //重复就跳过
    
    int twoSum = target-nums[k];
    int i=k+1, j=nums.size()-1;
    //two pointer
    while(i<j){
      if(nums[i] + nums[j] == twoSum){
        res.push_back({nums[k], nums[i], nums[j]});
        while(i < j && nums[j]==nums[i+1]) i++; //重复跳过
        while(i < j && nums[j]==nums[j-1]) j--;//重复跳过
        i++; j--;
      }
      else if(nums[i]+ nums[j] < twoSum) i++;
      else j--;
    }
  }
  return res;
}
// vector<vector<int>> threeSum(vector<int>& nums, int target){
//   set<vector<int>> res;
//   sort(nums.begin(), nums.end());
//   for(unsigned int k=0; k<nums.size(); k++){
//     int twoSum = target - nums[k];
//     int i=k+1, j=nums.size()-1;
//     while(i<j){
//       if(nums[i] + nums[j]== twoSum){
//         res.insert({nums[k], nums[i], nums[j]});
//         while(i<j && nums[i]==nums[i+1]) i++;
//         while(i<j && nums[j]==nums[j-1]) j--;
//         i++; j--;
//       }
//       else if(nums[i]+nums[j] < twoSum) i++;
//       else j--;
//     }
//   }
//   return vector<vector<int>>(res.begin(), res.end());
// }

int main(){
  vector<int> test={-1, 0, 1, 2, -1, -4};
  int target =3;
  
  vector<vector<int>>res=threeSum(test, target);
  for(unsigned int i=0; i<res.size(); i++){
    for(unsigned int j=0; j<res[0].size(); j++){
      cout<<res[i][j]<<", ";
    }
    cout<<endl;
  }
  return 0;
}