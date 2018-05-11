/*
https://leetcode.com/problems/longest-palindromic-subsequence/description/
"bbbab"
4
*/
int longestPalindromeSubseq(string s) {
    int n=s.size();
    vector<vector<int>> T(n, vector<int>(n, 0));
    for(int i=n-1; i>=0; i--){
        T[i][i]=1;//(0,0),(1,1),(2,2)
        for(int j=i+1; j<n; j++){
            if(s[i]==s[j]){
                T[i][j]= T[i+1][j-1]+2;
            }
            else
                T[i][j]= max(T[i+1][j], T[i][j-1]);         
        }
    }
    return T[0][n-1];
}
//=========================>优化为一维
int longestPalindromeSubseq(string s){
    int n=s.size(), longest_=0;
    vector<int> T(n, 1);
    for(int i=n-1; i>=0; i--){
        int len=0;
        for(int j=i+1; j<n; j++){
            int tmp = T[j];
            if(s[i]==s[j]){
                T[j]=len+2;
            }
            len = max(len, tmp);
        }
    }
    for(int num: T)
        longest_ = max(longest_, num);

    return longest_;
}