/*
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
https://leetcode.com/problems/longest-palindromic-substring/description/
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        int start;
        int n = s.length();
        bool dp[n][n] = {0};//false
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= i;j++){
                if(j == i){
                    dp[i][j] = 1;//只有一个字母
                } 
                else if(j == i - 1){
                    dp[i][j] = (s[i] == s[j]);//如果两端一样，则是pal
                } 
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i - 1][j + 1]);//如果两端一样，且中间/对角也是pal
                }
                
                if(dp[i][j] && (i - j + 1) > maxLength){
                    maxLength = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};