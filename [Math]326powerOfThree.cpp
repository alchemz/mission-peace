class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n > 1){
            while(n%3 == 0)
                n /= 3;
        }
        return n == 1;
    }
};
//https://leetcode.com/problems/power-of-three/description/