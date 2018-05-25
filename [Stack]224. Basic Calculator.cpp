/*
所以我们要用循环把之后的数字都读进来，然后用sign*num来更新结果res；
如果遇到了加号，则sign赋为1，如果遇到了符号，则赋为-1；
如果遇到了左括号，则把当前结果res和符号sign压入栈，res重置为0，sign重置为1；
如果遇到了右括号，结果res乘以栈顶的符号，栈顶元素出栈，结果res加上栈顶的数字，栈顶元素出栈。
*/
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