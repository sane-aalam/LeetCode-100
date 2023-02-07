
// 130. Surrounded Regions - Leetcode
// geeksforgeek - Replace o's into the x's

/*

note : given matrix change no need create copy matrix )
1.  if 0's is conncected to bounary then you can not replace into X
2.  if 0's is not conncected to bounary then you can replace into X

# Algorithm:
1 ) find the all boundry 0"s
2 ) traversal the all neigbours mark true
3 ) which one is not conncected to the boundary then you can convert into X

1. need - visted matrix
1. either you use BFS / DFs
1. you need to clear 4-directions
1. 4- directions = 4 

dfs algortim:
mark visited then checkout all directions4 

tc = 0(n*m)
sc = 0(n*m)


*/


class Solution {
private:
    // we create this function for storing the 0's visted into the matrix
    // according to boundaries 0's visted into the we will convert into the X
    void DFS(int row, int col,vector<vector<int>>&vis,vector<vector<char>>&board){

        // size of the matrix used for manage the traversalling part out the boundary 
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        // check out the left,right,top,bottom 
        // bascially we will be checking 0's neighbours

        // delrow and delcol pattern
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];


        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                    DFS(nrow,ncol, vis, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {

        // size of the matrix used for create new matrix - visted 2-D matrix
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        
        // 4-directions cover using traversal algorithm - you can use BFS and DFS
        // go the top and down

        for(int i = 0; i<m; i++){
            // go the top and check out the 0's persent 
            if(!vis[0][i] && board[0][i] == 'O'){
                DFS(0,i,vis,board);
            }
            // go the bottom and check out the 0's present
            if(!vis[n-1][i] && board[n-1][i] == 'O'){
                DFS(n-1,i,vis,board);
            }
        }

        // go the left and right
        for(int i = 0; i<n; i++){
            // go the left and check out the 0's the persent
            if(!vis[i][0] && board[i][0] == 'O'){
                DFS(i,0,vis,board);
            }
            // go the right and check out the 0's the persent
           if(!vis[i][m-1] && board[i][m-1] == 'O'){
                DFS(i,m-1,vis,board);    
           }
        }

        // if not visited any 0's
        // simple we can say - onone touched into 0's means' inside the boundary 
        // then we can convert into the nbv 0's -> x's

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
