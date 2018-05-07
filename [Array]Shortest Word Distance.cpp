class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> idx1, idx2;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) idx1.push_back(i);
            else if (words[i] == word2) idx2.push_back(i);
        }
        for (int i = 0; i < idx1.size(); ++i) {
            for (int j = 0; j < idx2.size(); ++j) {
                res = min(res, abs(idx1[i] - idx2[j]));
            }
        }
        return res;
    }
};
/*
http://www.cnblogs.com/grandyang/p/5187041.html
https://leetcode.com/problems/shortest-word-distance/description/
For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.
*/