class Solution {
public:
    void reverseWords(vector<char> &s) {
        int left = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, left, i - 1);
                left = i + 1;
            }
        }
        reverse(s, 0, s.size() - 1);
    }
    void reverse(vector<char> &s, int left, int right) {
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left; --right;
        }
    }
};
/*
lc:https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
sol:http://www.cnblogs.com/grandyang/p/5186294.html
*/