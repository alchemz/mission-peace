/*
http://www.cnblogs.com/grandyang/p/4481576.html
http://www.cnblogs.com/grandyang/p/4515925.html
http://www.cnblogs.com/grandyang/p/4130379.html
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
  set<vector<int>> res;
  sort(nums.begin(), nums.end());
  for(unsigned int i=0; i< (nums.size()-3); i++){
    for(unsigned int j=i+1; j< (nums.size()-2); j++){
      if(j > i+1 && nums[j]==nums[j-1]) continue;//重复
      //two pointers
      int left = j+1, right = nums.size()-1;
      while(left < right){
        int sum = nums[i]+ nums[j] + nums[left]+ nums[right];
        if(sum== target){
          vector<int> out{nums[i], nums[j], nums[left], nums[right]};
          res.insert(out);
          left++; right--;
        }else if(sum<target) left++;
        else right--;
      }
    }
  }
  return vector<vector<int>>(res.begin(), res.end()); 
}
     
int main(){
  vector<int> test={-1, 0, 1, 2, -1, -4};
  int target =3;
  
  vector<vector<int>>res=fourSum(test, target);
  for(unsigned int i=0; i<res.size(); i++){
    for(unsigned int j=0; j<res[0].size(); j++){
      cout<<res[i][j]<<", ";
    }
    cout<<endl;
  }
  return 0;
}