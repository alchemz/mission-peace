/*
递归 N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
皇后可以走任意方向，返回所有排列可能。
https://leetcode.com/problems/n-queens/description/
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        solveNQueensDFS(res, pos, 0);//从第一行开始
        return res;
    }
    
    void solveNQueensDFS(vector<vector<string>> &res, vector<int> &pos, int row){
        int n=pos.size();
        if(row == n){
            vector<string> out(n, string(n, '.'));
            for(int i=0; i<n; i++){
                out[i][pos[i]]='Q';//pos[i]表示第i行皇后位置
            }
            res.push_back(out);
        }else{
            for(int col=0; col<n; col++){
                if(isValid(pos, row, col)){
                    pos[row]=col;
                    solveNQueensDFS(res, pos, row+1);//扫描下一行
                    pos[row]=-1;
                }
            }
        }
    }
    
    bool isValid(vector<int> &pos, int row, int col){
        for(int i=0; i<row; i++){
            if(col==pos[i]|| abs(row-i) == abs(col-pos[i])){
                return false;
            }
        }
        return true;
    }
};