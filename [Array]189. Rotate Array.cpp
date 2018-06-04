// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//        for(size_t i=0; i<k; i++){
//            rotateOne(nums);
//        } 
//     }
    
//     void rotateOne(vector<int>& nums){
//         nums.insert(nums.begin(), nums.back());
//         nums.pop_back();
//     }
    
// };
// time: O(k), space: O(1)

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> t=nums;
//         for(size_t i=0; i<nums.size(); i++){
//             nums[(i+k)%nums.size()]=t[i];
//         }   
//     }
// };
// 利用 (i+k)%n的映射关系
// time: O(n), space: O(n)

class Solution{
public:
    void rotate(vector<int>& nums, int k){
        if(nums.empty() || (k%=nums.size())==0) return;
        int n=nums.size();
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

//space: O(1)
//先把前n-k个数翻转，再把后面k个数翻转，再把整个数组翻转。