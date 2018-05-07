/*
http://www.cnblogs.com/grandyang/p/4481576.html
http://www.cnblogs.com/grandyang/p/4515925.html
http://www.cnblogs.com/grandyang/p/4130379.html
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    //hashtable for key and mapped value
    unordered_map<int, int>mp;
    for(int i=0; i<(int)nums.size(); i++){
        if(mp.count(target-nums[i])){ //find the value
            return {i, mp[target-nums[i]]};
        }
        mp[nums[i]]=i; //find the next key
    }
    return {};
}

     
int main(){
  vector<int> test={2, 7, 11, 15};
  int target =9;
  vector<int> res=twoSum(test, target);
  for(int i=0; i<(int)res.size(); i++){
    cout<<res[i]<<", ";
  }
  return 0;
}