/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-substring-without.html
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //存储当前没有重复字符的substring的所有字符(key)以及它们的位置(val)。
        unordered_map<char, int> mp;
        int maxLen =0, curLen =0, start=0;
        
        for(int i=0; i<s.size(); i++){
            if(mp.count(s[i])){ //检测是否在表中
                for(int j=start; j<mp[s[i]]; j++){
                    mp.erase(s[j]);//删除start到i之间的字符
                }
                curLen = i-mp[s[i]];//记录之前组的长度
                start = mp[s[i]]+1;//检查下一组
            }else{
                curLen++;
            }
            mp[s[i]]=i;//当下一个字符s[i]仍然是新字符时，插入
            maxLen =max(maxLen, curLen);
        }
        return maxLen;
    }
};