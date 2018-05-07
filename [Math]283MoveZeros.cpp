#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int>& nums){
  unsigned int count=0;//count non-zeros
  for(unsigned int i=0; i<nums.size(); i++){
    if(nums[i]!=0){
      nums[count++]=nums[i];
    }
  }
  while(count<nums.size())
    nums[count++]=0;
}

int main(){
  vector<int> v={0, 1, 0, 3, 12};
  moveZeros(v);
  
  for(auto x: v)
    cout<<x<<" ";
  return 0;
}
