
/*  
 Approach - used :
 Backtacking + is it safe state ( right palce ) method used here :
 - try to fill the queen into the column
 - go the next column 
 - checkout the 
   possilbe fill the queen for this row and col :
   simple - they are not attacking order !
 
 
 
 N - queen 2 - we want to count of the total number of way fill the queen into chessboard correctly 
 we want to string way output :
 Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
  
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector < vector < string >> ans;
        vector < string > board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
    
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      // base condtion 
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
          board[row][col] = 'Q';
          dfs(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }
    
    // this function is used to checkout the all possilbe way to fill the queen into the chessboard
    
    bool isSafe(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }
};

// end of the code 
