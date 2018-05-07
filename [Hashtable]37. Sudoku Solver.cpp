#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char> > &board, int i, int j) {
    for (int col = 0; col < 9; ++col) {
        if (col != j && board[i][j] == board[i][col]) return false;
    }
    for (int row = 0; row < 9; ++row) {
        if (row != i && board[i][j] == board[row][j]) return false;
    }
    for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
        for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
            if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
        }
    }
    return true;
}
bool solveSudokuDFS(vector<vector<char> > &board, int i, int j) {
    if (i == 9) return true;
    if (j >= 9) return solveSudokuDFS(board, i + 1, 0);
    if (board[i][j] == '.') {
        for (int k = 1; k <= 9; ++k) {
            board[i][j] = (char)(k + '0');
            if (isValid(board, i , j)) {
                if (solveSudokuDFS(board, i, j + 1)) return true;
            }
            board[i][j] = '.';
        }
    } else {
        return solveSudokuDFS(board, i, j + 1);
    }
    return false;
}
    
void solveSudoku(vector<vector<char> > &board) {
    if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
    solveSudokuDFS(board, 0, 0);
}

int main()
{
  vector<vector<char>> board={{'5','6','.','8','4','7','.','.','.'},
                              {'3','.','9','.','.','.','6','.','.'},
                              {'.','.','8','.','.','.','.','.','.'},
                              {'.','1','.','.','8','.','.','4','.'},
                              {'7','9','.','6','.','2','.','1','8'},
                              {'.','5','.','.','3','.','.','9','.'},
                              {'.','.','.','.','.','.','2','.','.'},
                              {'.','.','6','.','.','.','8','.','7'},
                              {'.','.','.','3','1','6','.','5','9'}};
                              
                              
  solveSudoku(board);
  for(unsigned int i=0; i<board.size(); i++){
    for(unsigned int j=0; j<board[0].size(); j++){
      cout<<board[i][j]<<", ";
    }
    cout<<endl;
  }
  return 0;
}

//http://www.cnblogs.com/grandyang/p/4421852.html
//https://leetcode.com/problems/sudoku-solver/description/