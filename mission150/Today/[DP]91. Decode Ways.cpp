/*
'A' -> 1
'B' -> 2
...
'Z' -> 26
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

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
class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;        
        m_ways[""] = 1;        
        return ways(s);
    }
 
private:
    int ways(const string& s) {
        if (m_ways.count(s)) return m_ways[s];
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;        
        
        int w = ways(s.substr(1));        
        const int prefix = stoi(s.substr(0, 2));
        
        if (prefix <= 26)
             w += ways(s.substr(2));        
        
        m_ways[s] = w;        
        return w;
    }
 
    unordered_map<string, int> m_ways;
};
//O(n^2),
//O(n^2)
class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        return ways(s, 0, s.length() - 1);
    }
 
private:    
    int ways(const string& s, int l, int r) {        
        if (m_ways.count(l)) return m_ways[l];
        if (s[l] == '0') return 0;
        if (l >= r) return 1; // Single digit or empty.
        
        int w = ways(s, l + 1, r);
        const int prefix = (s[l] - '0') * 10 + (s[l + 1] - '0');
        
        if (prefix <= 26)
             w += ways(s, l + 2, r);
        
        m_ways[l] = w;
        return w;
    }
    
    // Use l as key.
    unordered_map<int, int> m_ways;
};

//time: O(n)
//space: O(n)