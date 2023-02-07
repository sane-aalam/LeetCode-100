

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // all 4-directions
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(!vis[i][j] && grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    } 
                }
            }
        }
        
        // start game here ->
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};

            for(int index = 0; index<4; index++){
                int nrow = row + delrow[index];
                int ncol = col + delcol[index];

                /*  3 cases follwed here 
                1. valid range 
                2. not visited 2D visted matrix
                3. it is land = 1

                if follow all the condtions then push into the queue,
                mark visted 

                */

                if(nrow >= 0 && nrow <n && ncol >=0 && ncol < m && 
                     !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;   
                }
            }
        }
        // any number of moves.
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};
