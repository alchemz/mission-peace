int longestUtil(vector<int> a, vector<int> b){
    int m=a.size();
    int n=b.size();
    vector<vector<int>> T(m+1, vector<int>(n+1));

    for(int i=0; i<T.size(); i++){
        for(int j=0; j<T[i].size();j++){
            if(i==0 || j==0)
                T[i][j]=0;
            else if(a[i-1]==b[j-1]){
                T[i][j]= 1 + T[i-1][j-1];
            }
            else{
                T[i][j]= max(T[i][j-1], T[i-1][j]);
            }
        }
    }

    return T[m][n];
}
/*
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
可以时间断的subsequence.
*/
//O(mn)
