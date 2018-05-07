#include <iostream>
#include <algorithm>
using namespace std;

int longestBitonic(vector<int> &nums){
    vector<int> lef(nums.size(), 1);
    vector<int> rig(nums.size(), 1);
    int max_=0;
    for(int i=1; i<nums.size(); i++){
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i]){
                lef[i]=max(lef[i], lef[j]+1);
            }
        }
    }
    
    for(int i=nums.size()-2; i>=0; i--){
        for(int j=nums.size()-1; j>i; j--){
            if(nums[j]<nums[i]){
                rig[i]=max(rig[i], rig[j]+1);
            }
        }
    }
    
    for(int i=0; i<nums.size(); i++){
        if(max_ < lef[i]+rig[i]-1){
            max_= lef[i]+rig[i]-1;
        }
    }
    
    return max_;
}
int main() {
	vector<int> nums={1, 11, 2, 10, 4, 5, 2, 1};
	cout<<"the result: "<<longestBitonic(nums)<<endl;
	return 0;
}