/*
与climbing stairs类似。
不同于一些限制，a.一位数不能为0, b. 两位数不能大于26, c其十位数上也不能为0

1.简历dp,初始为1
2. 从第三个数开始更新，对每一个数组线判断是否为0
3. 如果是0，则将dp赋值为0
4. 如果不是，赋值为上一个dp的值，此时相当如加上了dp[i - 1]
5. 然后看数组前一位是否存在，如果存在且满足前一位不是0，且和当前为一起组成的两位数不大于26，则当前dp值加上dp[i - 2]
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || (s.size()>1 && s[0]=='0'))  return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0]=1;
        
        for(int i=1; i< dp.size(); i++){
            dp[i]=(s[i-1]=='0')? 0:dp[i-1];
            if(i>1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))){
                dp[i] += dp[i-2];
            }
        }
        
        return dp.back();
    }
};