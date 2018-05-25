class Solution {
public:
    int calculate(string s) {
        stack<int> oprs;
        int res=0, num=0, sign=1, n=s.size();
        for(int i=0; i<n; i++){
            char c=s[i];
            if(c>='0'){
                num=10*num + (c-'0');
            }
            else if(c=='+' || c=='-'){
                res += sign *num;
                num=0;
                sign=(c=='+')? 1:-1;
            }
            else if(c=='('){
                oprs.push(res);
                oprs.push(sign);
                res=0;
                sign=1;
            }
            else if(c==')'){
                res+= sign*num;
                num=0;
                res *= oprs.top();
                oprs.pop();
                res += oprs.top();
                oprs.pop();
            }
        }
        res += sign* num;
        return res;
    }
};