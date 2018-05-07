class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return vector<vector<string> >();

        int len = strs.size();

        //将字符串数组按照字典顺序排序
        sort(strs.begin(), strs.end());

        //存储结果
        vector<vector<string> > ret;

        //利用哈希思想构建map，将排序后相等的字符串存在相应的vector
        map<string, vector<string>> mv;

        for (int i = 0; i < len; i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());

            mv[str].push_back(strs[i]);
        }

        for (map<string, vector<string> >::iterator iter = mv.begin(); iter != mv.end(); iter++)
            ret.push_back(iter->second);

        return ret;
    }
};

/*
sol:https://blog.csdn.net/fly_yr/article/details/48163005
lc: https://leetcode.com/problems/group-anagrams/description/

分类同构词，按照字典排序
输入：["eat", "tea", "tan", "ate", "nat", "bat"]
输出：
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

思路：
1.将字符串数组按照字典顺序排序
2.存储结果
3.利用哈希思想构建map，将排序后相等的字符串存在相应的vector
*/