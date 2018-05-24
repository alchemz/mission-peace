int longestUtil(vector<int> a, vector<int> b){
    vector<vector<int>> T(a.size()+1, vector<int>(b.size()+1));
    int max_=0;
    for(int i=1; i<T.size(); i++){
        for(int j=1; j<T[i].size();j++){
            if(a[i-1]==b[j-1]){
                T[i][j]= 1 + T[i-1][j-1];
            }else{
                T[i][j]= max(T[i][j-1], T[i-1][j]);
            }

            if(T[i][j] > max_){
                max_= T[i][j];
            }
        }
    }

    return max_;
}