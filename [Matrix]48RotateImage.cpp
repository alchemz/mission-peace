class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        //对角线
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }
        //中轴
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};

//rotate matrix in place
//http://www.cnblogs.com/grandyang/p/4389572.html
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++ ){
                //transpose
                swap(matrix[i][j], matrix[j][i]);
            }
            //reverse each row
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
