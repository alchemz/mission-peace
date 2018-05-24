/*
[["X","X","X","X"],
 ["X","O","O","X"],
 ["X","X","O","X"], 
 ["X","O","X","X"]]

[["X","X","X","X"],
 ["X","O","O","X"],
 ["X","X","O","X"],
 ["X","1","X","X"]]

 [["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","O","X","X"]]
*/

// https://leetcode.com/problems/surrounded-regions/discuss/41646/Concise-12ms-C++-DFS-solution

class Solution {
public:
  void solve(vector<vector<char>> &board){
  	if(board.empty())	return;
  	int row=board.size(), col=board[0].size();
  	for(size_t i=0; i<row; i++){
  		check(board, i, 0); //first col, 左边
  		check(board, i, col-1); //last col，右边
  	}
  	for(size_t j=1; j<col-1; j++){
  		check(board, 0, j); //first cow， 上边
  		check(board, row-1, j); //last cow， 下边
  	}
  	for(size_t i=0; i<row; i++){
  		for(size_t j=0; j<col; j++){
  			if(board[i][j]=='O')
  				board[i][j]='X';
  			else if (board[i][j]=='1')	
  				board[i][j]='O';
  		}
  	}
  }
private:
//先把边边上的O换成1, 然后遍历数组，把是O的转换成X, 1转换成O
  void check(vector<vector<char>> &board, int i, int j){
  	if(board[i][j]=='O'){
  		board[i][j]='1';
  		if(i>1)	check(board, i-1, j);//检查上边是否为边界
  		if(j>1)	check(board, i, j-1);//左
  		if(i+1<board.size()) check(board, i+1, j);//下
  		if(j+1<board[0].size())	check(board, i, j+1);//右
  	}
  }
};
/*
[["O","O","O"],
 ["O","O","O"],
 ["O","O","O"]]
if(i>1)	check(board, i-1, j);//上
if(j>1)	check(board, i, j-1);//左
if(i+1<board.size()) check(board, i+1, j);//下
if(j+1<board[0].size())	check(board, i, j+1);//右
是为了检查类似3*3矩阵的情况，检查是否为边界

*/