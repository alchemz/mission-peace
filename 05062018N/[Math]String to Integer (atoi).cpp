/*
Implement atoi which converts a string to an integer.

Input: "4193 with words"
Output: 4193

Input: "words and 987"
Output: 0

https://leetcode.com/problems/string-to-integer-atoi/description/
*/
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        
        int sign = 1, res = 0, i = 0, n = str.size();
        while (i < n && str[i] == ' ') ++i;//skip white spaces
        
        if (str[i] == '+' || str[i] == '-') {
            if(str[i++] == '+')
                sign = 1;
            else
                sign =-1;
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res = 10 * res + (str[i++] - '0');
        }
        return res * sign;
    }
};