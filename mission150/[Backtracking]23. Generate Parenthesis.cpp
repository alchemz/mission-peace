/*
用递归的方法，left, right分别记录左右剩余的括号数量
注意当left>right, 会有非法串)(
当left==right==0, 说明左右用完，存进vector<string>res中。
https://leetcode.com/problems/generate-parentheses/description/
http://www.cnblogs.com/grandyang/p/4444160.html
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res){
        if(left > right) return;//会出现非法串
        if(left ==0 && right==0) res.push_back(out);//左右3个用完
        else{
            if(left > 0) generateParenthesisDFS(left-1, right, out+'(', res);
            if(right > 0) generateParenthesisDFS(left, right-1, out+')', res);
        }
    }
};