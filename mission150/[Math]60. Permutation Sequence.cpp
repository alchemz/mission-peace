class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> factorial(n, 1);
        vector<char> num(n, 1);
        
        for(int i=1; i<n; i++){
            factorial[i]= factorial[i-1]*i;
        }
        //'1', '2', '3'...
        for(int i=0; i<n; i++){
            num[i]= (i+1)+'0';
        }
        
        k--;
        for(int i=n; i>=1; i--){
            int j= k/factorial[i-1];
            k %= factorial[i-1];
            res.push_back(num[j]);
            num.erase(num.begin()+j);
        }
        
        return res;
    }
};
//http://bangbingsyb.blogspot.com/2014/11/leetcode-permutation-sequence.html