class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> C(A.size(), vector<int>(B[0].size()));
        for(size_t i=0; i<A.size(); i++){
            for(size_t k=0; k<A[0].size(); k++){
                if(A[i][k]!=0){
                    for(size_t j=0; j<B[0].size(); j++){
                        if(B[k][j]!=0)
                            C[i][j] += A[i][k]*B[k][j];
                    }
                }
            }
        }
        return C;
    }
};

//稀疏矩阵的特点是有很多的零，所以注意处理0