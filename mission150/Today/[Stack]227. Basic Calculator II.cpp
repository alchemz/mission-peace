/*
由于存在运算优先级，我们采取的措施是使用一个栈保存数字，
如果该数字之前的符号是加或减，那么把当前数字压入栈中，
注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。
如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，
那么完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了。
*/
class Solution {
public:
    int calculate(string s) {
        int res = 0, d = 0;
        char sign = '+';
        stack<int> nums;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0') {
                d = d * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
                if (sign == '+') nums.push(d);
                if (sign == '-') nums.push(-d);
                if (sign == '*' || sign == '/') {
                    //int tmp = sign == '*' ? nums.top() * d : nums.top() / d;
                    int tmp=0;
                    if(sign == '*' ){
                        tmp=nums.top() * d;
                    }
                    if(sign =='/'){
                        tmp = nums.top() / d;
                    }
                    nums.pop();
                    nums.push(tmp);
                }
                sign = s[i];
                d = 0;
            } 
        }
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};