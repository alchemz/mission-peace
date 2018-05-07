class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int m=haystack.size(), n=needle.size();
        if(n>m) return -1;
        //遍历到剩下的长度和子字符串相等的位置
        for(int i=0; i<m-n; i++){
            int j=0;
            for(j=0; j<n; j++){
                if(haystack[i+j] != needle[j]) break;//如果对应位置有不等的，则跳出循环
                //else 继续循环
            }
            if(j==n) return i;//找到子字符串
        }
        return -1;
    }
};
//https://leetcode.com/problems/implement-strstr/description/