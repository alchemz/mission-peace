/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
动态规划
每个小的部分是matched, 合起来才是matched

类似题目有：https://leetcode.com/problems/regular-expression-matching/description/
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<bool>> T(m+1, vector<bool>(n+1, false));
        T[0][0]=true;
        for(int i=1; i<=n; i++){
            if(p[i-1]=='*')
                T[0][i]=T[0][i-1];
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[j-1]=='*'){
                    T[i][j]=T[i-1][j] || T[i][j-1];
                }
                else if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    T[i][j] = T[i-1][j-1];
                } 
            }
        }
        
        return T[m][n];
    }
};