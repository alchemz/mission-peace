/*
https://leetcode.com/submissions/detail/148347139/
*/
class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        if(n == 0){
            return(s);
        }
        
        int i,j;
        char temp;
        i = 0;
        j = n-1;
        while(i < j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i += 1;
            j -= 1;
        }
        return(s);
    }
};