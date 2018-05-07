// Running time: 23 ms
class Solution {
public:
  string reverseWords(string s) {    
    int index = 0;  
    for (int i = 0; i <= s.length(); ++i) {
      if (i == s.length() || s[i] == ' ') {
        std::reverse(s.begin() + index, s.begin() + i);
        index = i + 1;
      }
    }
    return s;
  }
};

/*

将字符串中每个单词逆转
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

思路：当检测到空格或者字符串末端的时候，reverse

leetcode:
https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

sol:
http://zxi.mytechroad.com/blog/string/leetcode-557-reverse-words-in-a-string-iii/
*/