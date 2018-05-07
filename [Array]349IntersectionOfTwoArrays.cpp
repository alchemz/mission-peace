#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash_set(nums1.begin(), nums1.end());
        vector<int> ret;
        for(auto it: nums2){
            if(hash_set.count(it)){
                ret.push_back(it);
                hash_set.erase(it);
            }
        }
        return ret;
}
int main(){
  vector<int> n1={1, 3, 4,2};
  vector<int> n2={2,3,0,7};
  vector<int> ans=intersection(n1, n2);
  
  for(auto it: ans)
    cout<<it<<" ";
  return 0;
}
