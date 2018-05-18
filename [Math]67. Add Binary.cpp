/*
如果需要从后往前加，记录carry.
如果输入的是string, 可以考虑先reverse

注意存储的时候 carry+'0', 从int 转换成 char
https://leetcode.com/problems/add-binary/description/
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int s1=a.size(), s2=b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());//从后往前加
        int n=max(s1, s2);
        int carry = 0;
        string sum="";
        for(int i=0; i<n; i++){
            if(i<s1)    carry += a[i]-'0';//string a非空
            if(i<s2)    carry += b[i]-'0';
            
            sum.push_back(carry%2+'0');
            carry = carry/2;
        }
        if(carry)   sum.push_back(carry +'0');
        reverse(sum.begin(),sum.end());
        
        return sum;
    }
};