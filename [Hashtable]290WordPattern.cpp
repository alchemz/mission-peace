class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> map2;
        vector<string> vec;
            
        int j = 0;
        for (int i = 0; i<str.size(); i++){
            if (str[i] == ' '){
                string tmp = str.substr(j, i - j);
                vec.push_back(tmp);
                j = i + 1;
            }
            if (i == str.size() - 1){
                string tmp = str.substr(j, i - j + 1);
                vec.push_back(tmp);
            }

        }
        if (pattern.size() != vec.size())
            return false;
        for (int i = 0; i<pattern.size(); i++){
            if (map.find(pattern[i]) == map.end() && map2.find(vec[i]) == map2.end()){
                map.insert(make_pair(pattern[i], vec[i]));
                map2.insert(make_pair(vec[i], pattern[i]));
            }
            else if (map[pattern[i]] != vec[i] || map2[vec[i]] != pattern[i])
            {
                    return false;
            }
        }
        return true;
    }
};

//http://blog.51cto.com/qiaopeng688/1836427
//https://leetcode.com/problems/word-pattern/description/