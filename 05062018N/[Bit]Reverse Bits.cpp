class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0; i<32; i++){
            if(n & 1==1){
                res = (res<<1)+1;
            }else{
                res =res<<1;
            }
            n=n>>1;
        }
        
        return res;
    }
};

/*
https://www.geeksforgeeks.org/reverse-actual-bits-given-number/
https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
https://leetcode.com/problems/reverse-bits/description/
http://www.cnblogs.com/grandyang/p/4321355.html
*/
