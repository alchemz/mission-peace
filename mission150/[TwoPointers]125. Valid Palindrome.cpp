/*
时间复杂度: O(n)
注意在用while loop迭代的时候，要注意更新start++, end--
https://leetcode.com/problems/valid-palindrome/description/
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0, end=s.size()-1;
        while(start < end){
            if(!isalnum(s[start]))   start++;
            else if(!isalnum(s[end])) end--;
            else{
                // if(tolower(s[start])!=tolower(s[end]))return false;
                // start++;
                // end--;
                //简写成下面
                if(tolower(s[start++])!=tolower(s[end--])) return false;
            }
        }
        return true;
    }
};