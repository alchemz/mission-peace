// Time complexity: O(n)
// Space complexity: O(128) = O(1)
// Running time: 3 ms 9/2017
class Solution {
public:
    int longestPalindrome(const string& s) {
        vector<int> freqs(128, 0);
        for (const char c : s)            
            ++freqs[c];
 
        int ans = 0;
        int odd = 0;
        for (const int freq : freqs) {            
            ans += freq % 2 == 0 ? freq : freq - 1;
            // same as: ans += freq / 2 * 2;
            // same as: ans += ((freq >> 1) << 1);            
            // same as: ans += freq & (INT_MAX - 1);
            //ans += freq & (~1); // clear the last bit
            odd |= freq & 1;
        }
        
        ans += odd;
        
        return ans;
    }
};
//https://leetcode.com/problems/longest-palindrome/description/