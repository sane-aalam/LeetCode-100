

// Easy problem - you think easy then it's easy otherwise it's hard 


class Solution {
 public:
 /* there are three conditions 
    1- checkout the row wise
    2 - checkout the column wise
    3- checkout the sub-matrix 3*3
 */
 bool isSafe(int row,int col,char &c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) //Checking Row
                return false;
            if(board[row][i]==c) //Checking Column
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) //Checking 3*3 sub-matrix for unique number betweeen 1-9
                return false;
        }
        return true;
    }
    
    // identification = you have choice (you can include 1 to 9)
    // which data structure are used here - you have choice - 100% recursive tree and recursion

    // traversal the matrix
    // ask - it is empty cell if this is empty cell
    // ask - it is right place to fill the 1 to 9 
    // if you are able to fill 1-9 return ture;
    // if you are not able to fill 1-9 return false;

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){ // Traversal through each element in 9*9 Sudoku
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){ // If Empty
                    for(char c='1';c<='9';c++){
                        if(isSafe(i,j,c,board)==true){ 
                            //Checking whether 1-9 which numbers sets the 3 Sudoku Criteria
                            board[i][j]=c;
                            if(solve(board)==true) //Condition Checking
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
