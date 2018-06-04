/*
O(1)
Rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

logic: 
检查每行，if '.', skip
检查每列, if '.', skip
检查3X3, if '.', skip
注意3X3的排列规律
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
/*
simplified version
O(1)
*/
bool isValidSudoku(vector<vector<char> > &board)
{
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    
    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if(used1[i][num] || used2[j][num] || used3[k][num])
                    return false;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }
    
    return true;
}