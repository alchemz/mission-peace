/*
注意"]{"的情况，即一对都存不进stack中时，是false
每当有 ], ), }右边括号的时候，注意查找当前stack.top()是否为相符的左括号
https://leetcode.com/problems/valid-parentheses/description/
*/
class Solution {
public:
    bool isValid(string s) {
        if((int)s.size()%2==1) return false;
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else
            {
                if(st.empty()) return false;//一对都没有存进过
                if(s[i]==')' && st.top() != '(') return false;
                if(s[i]==']' && st.top() != '[') return false;
                if(s[i]=='}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty()? true:false;
    }
};