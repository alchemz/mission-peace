class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int i = 0; i < m[word1].size(); ++i) {
            for (int j = 0; j < m[word2].size(); ++j) {
                res = min(res, abs(m[word1][i] - m[word2][j]));
            }
        }
        return res;
    }
    
private:
    unordered_map<string, vector<int> > m;
};
/*
https://leetcode.com/problems/shortest-word-distance-ii/description/
http://www.cnblogs.com/grandyang/p/5187640.html

这道题是之前那道Shortest Word Distance的拓展，不同的是这次我们需要多次调用求最短单词距离的函数，
那么用之前那道题的解法二和三就非常不高效，而当时我们摒弃的解法一的思路却可以用到这里，
我们用哈希表来建立每个单词和其所有出现的位置的映射，然后在找最短单词距离时，
我们只需要取出该单词在哈希表中映射的位置数组进行两两比较即可
*/