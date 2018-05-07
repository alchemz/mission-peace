/*
next(): return next common element
hasNext(): judge if common element existed
*/
#include<bits/stdc++.h>
using namespace std;

class CommonIterator{
private:
  int i=0;
  vector<int> ans;
  
public:
  CommonIterator(vector<int>& nums1, vector<int>& nums2){
    unordered_set<int> m(nums1.begin(), nums1.end());
     
    for(int num: nums2){
      if(!m.count(num)) continue;
      ans.push_back(num);
      m.erase(num);
    }    
  }
  
  int next(){
    return ans[i++];
  }
  
  bool hasNext(){
    return i<(int)ans.size();
  }
};

int main(){
  vector<int> nums1={5,1,2,3};
  vector<int> nums2={7,2};
  CommonIterator c(nums1, nums2);
  while(c.hasNext())
    cout<<c.next()<<" "<<endl;
  return 0;
}
  
