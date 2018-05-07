#include<bits/stdc++.h>
using namespace std;

int maxSubArr(vector<int>& nums){
    vector<int> f(nums.size());
    f[0]=nums[0];
    for(unsigned i=1; i<nums.size(); i++)
        f[i]=max(f[i-1]+nums[i], nums[i]);
    
    return *max_element(f.begin(), f.end());
}

int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int ans=nums[0];
        for(unsigned i=1; i<nums.size(); ++i){
            sum=max(sum+nums[i], nums[i]);
            if(sum>ans) ans=sum;
        }
        return ans;
}

int main(){
   int arr[]={-2,1,-3,4,-1,2,1,-5,4};
   vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
   cout<<"The ans is: "<<maxSubArr(vec);
   return 0;
}
