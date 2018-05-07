
//http://wowaccepted.com/2018/01/23/leetcode-772-basic-calculator-iii%E9%A2%98%E7%9B%AE%E8%A7%A3%E6%9E%90-wowac/
//https://blog.csdn.net/magicbean2/article/details/79642344

#include<bits/stdc++.h>
using namespace std;

class Calculator {  
public:  
    int calculate(string s) {  
        int i = 0;  
        return parseExpr(s, i);  
    }  
private:  
    int parseExpr(string &s, int &i) {  // parse exp, i, global declared, pass by reference 
        vector<int> nums;  
        char sign = '+';  
        int n;  
        for (; (unsigned)i < s.length() && sign != ')'; ++i) {  
            if (s[i] == ' ') continue;   
            if (s[i] == '(')  n = parseExpr(s, ++i);  
            else  n = parseNum(s, i);  
          
            switch(sign) {  
                case '+':  
                    nums.push_back(n);  
                    break;  
                case '-':  
                    nums.push_back(-n);  
                    break;  
                case '*':  
                    nums.back() *= n;  
                    break;  
                case '/':  
                    nums.back() /= n;  
                    break;  
            }  
            sign = s[i];  
        }  
        int res = 0;  
        for (int n : nums) {  
            res += n;  
        }  
        return res;  
    }  
      
    int parseNum(string &s, int &i) {       // parse the num  
        int num = 0;  
        while ((unsigned)i < s.length() && isdigit(s[i])) {  
            num = 10 * num + s[i++] - '0';  
        }  
        return num;  
    }  
};  
int main(){
  Calculator cac;
  string s="123-234- (2-2)*2";
  cout<<cac.calculate(s);
  return 0;
}