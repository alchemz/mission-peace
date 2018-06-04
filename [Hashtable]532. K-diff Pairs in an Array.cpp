class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int pairs=0, n=nums.size();
        for(int num:nums)
            ++mp[num];//记录这个数一次
        for(auto a: mp){
            if(k==0 && a.second>1)  pairs++; //同样的数相减得0
            if(k>0 && mp.count(a.first+k))  pairs++; //找到表中对应的数
        }
        return pairs;
    }
};

/*
算法，用哈希表记录array中的数字，和对应个数
分两种情况，如果要求的差值是0，则对应个数>1，就算一组
如果要求差值>0, 则找哈希表中是否有a.first+k的数，有的话算一组。
*/