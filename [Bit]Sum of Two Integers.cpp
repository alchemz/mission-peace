/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
https://leetcode.com/problems/sum-of-two-integers/description/
http://www.cnblogs.com/grandyang/p/5631814.html
*/
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
    }
};