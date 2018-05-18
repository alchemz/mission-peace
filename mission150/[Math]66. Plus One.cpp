/*
注意处理digits[i]==9的状况，变成0
https://leetcode.com/problems/plus-one/description/
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for(int i=len-1; i>=0; i--){
            if(digits[i]==9){
                digits[i]=0;
            }
            else{
                digits[i] +=1;
                return digits;
            }
        }
        if(digits.front()==0) 
            digits.insert(digits.begin(),1);
        
        return digits;
    }
};