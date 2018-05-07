class Solution {
public:
    bool isPowerOfTwo(int n) {
         int cnt=0;
        while(n>0){
            cnt += (n &1);//数有几个1
            n >>=1;//位移下一个
        }
        return cnt==1;//统计1的个数
    }
};
//https://leetcode.com/problems/power-of-two/description/
