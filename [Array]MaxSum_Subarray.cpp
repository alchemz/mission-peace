#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindMaxSubarray(const vector<int> &nums){
    int size_=nums.size();
    int max_sum=0,sum=0;
    for(int i=0; i<size_; i++){
        sum += nums[i];
        if(sum > max_sum){
            max_sum=sum;
        }
    }
    return max_sum;
}

int main(){
    vector<int> nums={904, 40, 523, 12, -335, -385, -124, 481, -31};
    cout<<FindMaxSubarray(nums);
    
    return 0;
}