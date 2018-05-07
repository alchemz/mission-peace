class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0 )
            return false;
        if( ( (num)&(num-1) ) )//判断是否为2的幂
            return false;
            //0x55555555的二进制表示为
            //01010101010101010101010101010101
            //将目标数过滤出来
        if( ( (num) & (0x55555555) ) == num)
            return true;
        return false;
    }
};
//http://blog.51cto.com/qiaopeng688/1837900
//https://leetcode.com/problems/power-of-four/description/