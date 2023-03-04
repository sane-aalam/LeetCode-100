/*  
 Approach - used :
 Backtacking + is it safe state ( right palce ) method used here :
 - try to fill the queen into the column
 - go the next column 
 - checkout the 
   possilbe fill the queen for this row and col :
   simple - they are not attacking order !
 
 
 
 N - queen 2 - we want to count of the total number of way fill the queen into chessboard correctly 
 we want to integer answer 
 Input: n = 4
Output: 2
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

class Solution {
public:
    int totalNQueens(int n) {
        vector < string > board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        int result = solve(0, board);
        return result
    }
    
    // solve - this function are used to fill the queen into chessboard if it is possible to fill the queen!
    
    
    int solve(int col, vector < string > & board) {
      // base condtion - you completed traversal all the column, then backtrack ):
      if (col == board.size()) {
        return 1;
      }
      int count = 0;
      for (int row = 0; row < board.size(); row++) {
        if (isSafe(row, col, board)) {
          board[row][col] = 'Q';
          count += solve(col + 1, board);
          board[row][col] = '.';
        }
      }
      return count;
    }
    
    // isSafe - this function are used for checkout the this place correct to fill the queen 
    
    bool isSafe(int row, int col, vector < string > board) {
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
      int n = board.size();
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }
};
