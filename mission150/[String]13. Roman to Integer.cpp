/*
简单的规律
1.[i]>=[i+1]||最后一位 加上这个数
2.[i]<[i+1] 减去这个数
https://leetcode.com/problems/roman-to-integer/description/
time O(n)
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>mp={{'I',1},{'V',5},{'X',10},
                                      {'L',50},{'C',100},
                                      {'D',500},{'M',1000}};
        int res=0;
        for(int i=0; i<s.size(); i++){
            int val = mp[s[i]];
            if(i==s.size()-1||  mp[s[i]] >= mp[s[i+1]]){
                res += val;
            }
            else{
                res -= val;
            }
        }
        return res;
    }
};
