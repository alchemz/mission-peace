#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  int n=nums.size();
  vector<int> fwd(n,1);
  vector<int> bwd(n,1);
  vector<int> ans(n);
  for(int i=0; i<n-1; i++){
    fwd[i+1]=fwd[i]*nums[i];
  }
  for(int i=n-1; i>0; i--){
    bwd[i-1]=bwd[i]*nums[i];
  }
  for(int i=0; i<n; i++){
    ans[i]=fwd[i]*bwd[i];
  }
  return ans;
       
}

int main(){
    int arr[]={1,2,3,4};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    v=productExceptSelf(v);
    for(auto i=v.begin(); i!=v.end();i++)
      cout<<*i<<" ";
    return 0;
}
