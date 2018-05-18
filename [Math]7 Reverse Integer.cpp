/*
Input: 123
Output: 321

Input: -123
Output: -321

Input: 120
Output: 21
https://leetcode.com/problems/reverse-integer/description/
*/
class Solution {
public:
    int reverse(int x) {
        long long rev_num=0;
        bool negative=false;
        if(x<0){
            negative=true;
            x=-x;
        }

        while(x>0){
            rev_num= rev_num*10 + x%10;
            x = x/10;
        }
        if(rev_num > INT_MAX) return 0;
        
        return (negative == true) ? -rev_num : rev_num;
    }
};