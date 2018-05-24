class Solution {
public:
   string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
       //直接用个int的数组来代替，因为ASCII只有256个字符，所以用两个大小为256的int数组即可代替哈希表
        int tm[256] = {0}, sm[256] = {0};
       //扫描一遍T，把对应的字符及其出现的次数存到
        for (int i = 0; i < T.size(); ++i) ++tm[T[i]];
       //遍历S，遇到T中的字符，就把对应的哈希表中的value减一
        for (int right = 0; right < S.size(); ++right) {
            if (tm[S[right]] != 0) {
                ++sm[S[right]];
                if (sm[S[right]] <= tm[S[right]]) ++count;
                while (count == T.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (tm[S[left]] != 0) {
                        --sm[S[left]];
                        if (sm[S[left]] < tm[S[left]]) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};