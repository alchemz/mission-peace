/*
Input: "Hello World"
Output: 5
https://leetcode.com/problems/length-of-last-word/description/
记录最后一个单词的长度
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        //用curLen记录当前单词的长度
        //主要看S[i]如果不是空格, S[i-1]是空格，则是一个新单词，计数1
        int curLen = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] !=' '){
                if(s[i-1]==' ' && i!=0) curLen=1;
                else    curLen++;
            }
        }
        return curLen;
    }
};