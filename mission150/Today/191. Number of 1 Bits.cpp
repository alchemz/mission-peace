class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(size_t i=0; i<32; i++){
            count += n&1;
            n>>=1;
        }
        return count;
    }
};

/*
用count记录n中有多少个1
n&1 返回1，当这个bit是1
然后n左移1位， n>>=1
*/