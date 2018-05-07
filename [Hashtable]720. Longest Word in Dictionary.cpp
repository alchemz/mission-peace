//brute force+pruning
class Solution {
public:
    string longestWord(vector<string>& words) {
        string best;//the empty string
        unordered_set<string> dict(words.begin(), words.end());
        
        for(const string& word: words){
            //pruning
            if(word.length()<best.length()||(word.length()==best.length() && word>best))
                continue; //skip for checking
            string prefix;
            bool valid=true;
            for(int i=0; i<word.length()-1&&valid; ++i){
                prefix += word[i];
                if(!dict.count(prefix)) valid=false; //if the word is not in dictionary
            }
            if(valid) best=word; //if found, assign value to best
        }
        return best;
    }
};

/*
sol:http://zxi.mytechroad.com/blog/string/leetcode-720-longest-word-in-dictionary/
leetcode:https://leetcode.com/problems/longest-word-in-dictionary/description/

给一组字符串，代表字典，找到字典中，能由其他字符串组成的最长的字符串。
输入：["w","wo","wor","worl", "world"]
输出："world"
*/