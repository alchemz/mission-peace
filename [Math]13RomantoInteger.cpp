class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char, int>mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        for(int i=0; i<s.size(); i++){
            int value = mp[s[i]];
            if(i==s.size()-1 || mp[s[i+1]]<=mp[s[i]]) 
                ans+=value;
            else 
                ans-= value;            //IV, XL, CD
        }
        return ans;
    }
};
/*
https://leetcode.com/problems/roman-to-integer/description/
http://www.cnblogs.com/grandyang/p/4120857.html
*/
