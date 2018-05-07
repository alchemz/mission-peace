/*
https://leetcode.com/problems/implement-strstr/description/
Input: haystack = "hello", needle = "ll"
返回起始位置
*/
int strStr(string haystack, string needle) {
    if(needle.empty()){
        return 0;
    }
    int m=haystack.size(), n=needle.size();
    if(m<n){
        return -1;
    }
    for(int i=0; i<=m-n; i++){ //m-n 剩余字符不足，则不用测试
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