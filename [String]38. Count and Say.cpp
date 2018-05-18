/*
1: 1, one 1
2: 11, two 1
3: 21, one 2, one 1 =
4: 1211, one 1 one 2, two 1 = 5
5: 111221, three 1, two two, 1 one =6
就是第i+1个字符串是第i个字符串的读法
https://leetcode.com/problems/count-and-say/description/
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n<= 0) return "";
        string res="1";
        while(--n){
            string cur="";
            for(int i=0; i<res.size(); i++){
                int cnt=1;
                while(i+1<res.size() && res[i]==res[i+1]){
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res=cur;
        }
        return res;
    }
};