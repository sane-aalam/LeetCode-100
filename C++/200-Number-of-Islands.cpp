
//1. give the matrix think about how to use BFS and DFS
//2. when element is touch then how to touch 8 direction neighbous elemenet 
//3. using -1 to +1 
//
//   **condions : **
//a ) if row and col is valid 
//b ) if i have to be insland , means this is not water matrix[i][j] == "1"
//c ) don't already visited 

/* swal ye rahi aapki akhon ke sammne kya hai
 swal ye hay ki app dekh kya rahe hay*/

// you can use bfs and dfs ! no problem 


class Solution {
private:
    void BFS(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[]={-1,0,1,0};
            int delcol[]={0,-1,0,1};

            for(int k = 0; k<4; k++){
                int newrow = row + delrow[k];
                int newcol = col + delcol[k];

                if(newrow>=0 && newrow < n && newcol >= 0 && newcol < m &&
                 grid[newrow][newcol] == '1' && vis[newrow][newcol] == 0){    
                      vis[newrow][newcol] = 1;
                    q.push({newrow,newcol});
                }

            }
        } 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int count = 0;
        for(int i =0;i<n; i++){
            for(int j = 0; j<m; j++){
                // if it not visited and grid contains 1 means ( A land )
                if(!vis[i][j] && grid[i][j] == '1'){
                    count ++;
                    BFS(i,j,vis,grid); // breath FIRST SEARCH CALLING  
                }
            }
        }
        return count;
    }
};
