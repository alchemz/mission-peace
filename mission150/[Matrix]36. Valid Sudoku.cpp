/*
36. Valid Sudoku
rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

https://leetcode.com/problems/valid-sudoku/description/
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() !=9 || board[0].size() !=9) return false;
        
        //check row
        for(int i=0; i<9; i++){
            //行相同
            vector<bool> used(9, false);
            for(int j=0; j<9; j++){
                if(!isdigit(board[i][j])) continue;//skip '.'
                int k=board[i][j]-'0';
                if(k==0 || used[k-1]) return false;
                used[k-1]=true;
            }
        }
        
        //check col
        for(int j=0; j<9; j++){
            //列相同
            vector<bool> used(9, false);
            for(int i=0; i<9; i++){
                if(!isdigit(board[i][j])) continue;
                int k=board[i][j]-'0';
                if(k==0 || used[k-1]) return false;
                used[k-1]=true;
            }
        }
        
        //check subbox
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int row = 3*i;
                int col = 3*j;
                vector<bool> used(9, false);
                for(int m=row; m<row+3; m++){
                    for(int n=col; n< col+3; n++){
                        if(!isdigit(board[m][n])) continue;
                        int k = board[m][n]-'0';
                        if(k==0 || used[k-1]) return false;
                        used[k-1]=true;
                    }
                }
            }
        }
        
        return true;
    }
};