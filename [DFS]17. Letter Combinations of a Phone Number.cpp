class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //1. corner case
        if(digits.empty()) return {};
        //2.create 2d char array 
        vector<vector<char>>d(10);
        d[0]={' '};
        d[1]={};
        d[2]={'a','b','c'};
        d[3]={'d','e','f'};
        d[4]={'g','h','i'};
        d[5]={'j','k','l'};
        d[6]={'m','n','o'};
        d[7]={'p','q','r','s'};
        d[8]={'t','u','v'};
        d[9]={'w','x','y','z'};
        string cur;
        vector<string> ans;
        int idx;
        dfs(digits, d, idx, cur, ans);
        
        return ans;
    }
private:
    void dfs(string& digits, vector<vector<char>>& d, int idx, string& cur, vector<string>& ans){
        //if all scanned
        if(idx==digits.length()){
            ans.push_back(cur);
            return;
        }
        //add char and char
        for(char c: d[digits[idx]-'0']){
            cur.push_back(c);
            dfs(digits, d, idx+1, cur, ans);
            cur.pop_back();
        }
    }
};

/*
sol:http://zxi.mytechroad.com/blog/searching/leetcode-17-letter-combinations-of-a-phone-number/
lc:https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

给一个字符串代表电话上的数字按键，返回所有可能的字符串组合

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/