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
        res = res*res;
        
        if(n % 2 !=NULL)
            return res*x;
        return res;
    }
};

/*
基本思路，为了防止overflow, res=myPow(x, n/2), 一半*一半, res*res
如果n是奇数，则再res*x

*/
