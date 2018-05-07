class Solution {
public:
    int numSquares(int n) {
        while(n % 4 ==0) n /=4;
        if(n%8==7) return 4;
        for(int a=0; a*a <=n; a++){
            int b= sqrt(n- a*a);
            if(a*a + b*b==n){
                //都为正整数的话返回2，只有一个是正整数的话返回1
                return !!a + !!b;
            }
        }
        return 3;
    }
};