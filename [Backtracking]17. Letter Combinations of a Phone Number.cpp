/*
根据按键，输出电话号码的字母组合

思路：
用递归来做，建立一个字典，来保存每个数字所代表的字符串，
然后用一个变量level, 记录当前生成的字符串个数

类似题目: 类似的题目有 Path Sum II 二叉树路径之和之二，Subsets II 子集合之二，Permutations 全排列，
Permutations II 全排列之二，Combinations 组合项， Combination Sum 组合之和和 Combination Sum II 组合之和之二等等

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

class Solution {
public:
    void letterCombinationDFS(string digits, string dict[], int level, string out, vector<string> &res){
        if(level==digits.size()) res.push_back(out);//level记录查了几个按键
        else{
            string str = dict[digits[level]-'2'];//按键从2开始
            for(int i=0; i<str.size(); i++){
                out.push_back(str[i]);
                letterCombinationDFS(digits, dict, level+1, out, res);
                out.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits){
        vector<string> res;
        if(digits.empty()) return res;
        string dict[]={"abc","def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterCombinationDFS(digits, dict, 0, "", res);
        return res;
    }
};