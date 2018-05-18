/*
注意：用i+j来记录haystack的扫描位置
当[i+j] != [j]的时候，是影响后面的，所以用Break
https://leetcode.com/problems/implement-strstr/description/
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        int m=haystack.size(), n=needle.size();
        if(m<n){
            return -1;
        }
        for(int i=0; i<=m-n; i++){
            int j=0;
            for(j=0; j<n; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j==n){
                return i;
            }
        }
        
        return -1;
    }
};