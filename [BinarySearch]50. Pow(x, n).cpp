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