class WordFilter {
public:
    WordFilter(vector<string> words) {
        for (int k = 0; k < words.size(); ++k) {
            for (int i = 0; i <= words[k].size(); ++i) {
                for (int j = 0; j <= words[k].size(); ++j) {
                    m[words[k].substr(0, i) + "#" + words[k].substr(words[k].size() - j)] = k;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        return (m.count(prefix + "#" + suffix)) ? m[prefix + "#" + suffix] : -1;
    }

private:
    unordered_map<string, int> m;
};
http://www.cnblogs.com/grandyang/p/8331660.html
https://leetcode.com/problems/prefix-and-suffix-search/description/