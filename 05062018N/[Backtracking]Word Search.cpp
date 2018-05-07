class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if(board.size()==0) return false;
        h = board.size();
        w = board[0].size();
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++)
                if(search(board, word, 0, i, j)) return true;
        return false;
    }
    
    bool search(vector<vector<char>> &board, 
             const string& word, int d, int x, int y) {
        if(x<0 || x==w || y<0 || y==h || word[d] != board[y][x]) 
            return false;
        
        // Found the last char of the word
        if(d==word.length()-1)
            return true;
        
        char cur = board[y][x];
        board[y][x] = 0; 
        bool found = search(board, word, d+1, x+1, y)
                  || search(board, word, d+1, x-1, y)
                  || search(board, word, d+1, x, y+1)
                  || search(board, word, d+1, x, y-1);
        board[y][x] = cur;
        return found;
    }
private:
    int w;
    int h;
};
/*
sol: http://zxi.mytechroad.com/blog/leetcode/leetcode-79-word-search/
lc: https://leetcode.com/problems/word-search/description/
给一个2D棋盘，格子中有字母，搜索相邻棋盘中是否有目标字符串
输入：
board=[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word="ABCCED"
输出：true
思路：depth first search
*/