class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};
/*
lc:https://leetcode.com/problems/longest-palindromic-substring/description/
sol:http://www.cnblogs.com/grandyang/p/4464476.html
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool T[n][n]={0};
        int start;
        int maxLen =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j==i){
                    T[i][j]=1;
                }
                else if (j==i-1){
                    T[i][j]=(s[i]==s[j]);
                }
                else{
                    T[i][j]=(s[i]==s[j] && T[i-1][j+1]);
                }
                
                if(T[i][j] && maxLen < i-j+1){
                    maxLen = i-j+1;
                    start = j;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};