/*
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

记录有多少组有效括号
https://leetcode.com/problems/longest-valid-parentheses/description/
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0, start=0;
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                st.push(i);//记录坐标
            else if(s[i]==')'){
                if(st.empty())
                    start = i + 1;
                else{
                    st.pop();
                    if(st.empty())
                        res= max(res, i-start+1);
                    else
                        res= max(res, i-st.top());
                }
            }
        }
        return res;
    }
};