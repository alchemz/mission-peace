#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums){
  vector<int> ret;
  vector<pair<int, int>>v; //pair,保留原数组序号
  unordered_map<int, int> mp;//hashtable建立每个数组中，数字出现个数的映射
  
  for(unsigned i=0; i<nums.size(); i++){
    for(int num: nums[i]){
      v.push_back({num, i});//{4,0},{10,0}
    }
  }
  
  sort(v.begin(), v.end());
  
  int left=0, n=v.size(), k=nums.size(), cnt=0, diff=INT_MAX;
  // n=13, k=3;
  for(int right=0; right<n; right++){
    if(mp[v[right].second]==0) ++cnt;//right指向的数字所在数组没有被覆盖到
    ++mp[v[right].second];
    
    //变量cnt表示当前窗口中的数字覆盖了几个数组，diff为窗口的大小
    while(cnt==k && left<=right){
      if(diff>v[right].first - v[left].first){
        diff=v[right].first - v[left].first;
        ret={v[left].first, v[right].first};
      }
      //左移，如果此时映射值为0了，说明我们有个数组无法覆盖到了，cnt就要自减1
      if(--mp[v[left].second]==0) --cnt;
      ++left;
    }
  }
  return ret;
}

int main(){
  vector<vector<int>>nums={{4,10,15,24,26},{0,9,12,20}, {5,18,22,30}};
  vector<int>v=smallestRange(nums);
  for(auto i=v.begin(); i!=v.end(); i++){
    cout<<*i<<" ";
  }
  return 0;
}
  
