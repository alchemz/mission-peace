 bool repeatedSubstringPattern(string s) {
        if (s.length() <= 0)
            return false;
        for (int i = 1; i <= s.length()/2; i++) {
            // if i is a multiple
            if (s.length() % i == 0) {
                // string rotation 
                // if the substr is a valid repeatable substr
                // e.g. str(0,3) should equal str(6,9)
                // for abcabcabc
                if (s.substr(i) == s.substr(0,s.length()-i))
                    return true;
            }
        }
        return false;
}

/*
判断是否由重复字符串排列组成
输入："abab"
输出：true

输入："abcabcabcabc"
输出：true

https://leetcode.com/problems/repeated-substring-pattern/description/

sol:
http://blog.leanote.com/post/westcode/8df0baa2ece9
*/