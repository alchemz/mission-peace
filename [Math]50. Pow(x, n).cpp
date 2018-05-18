/*
防止溢出
用递归来折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1
这时候我们再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。
https://leetcode.com/problems/powx-n/description/

类似：69   Sqrt(x)  
https://leetcode.com/problems/sqrtx/description/  
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n>0)
            return myPowPos(x, n);
        else
            return 1/myPowPos(x, -n);
    }
    
    double myPowPos(double x, int n){
        if(n==0) return 1;
        
        double res;
        res = myPowPos(x, n/2);
     
        if(n % 2 ==0) 
            return res*res;
        return res*res*x;
    }
};