//694. Number of Distinct Islands - premium questions


// number of islands pattern questions + mathimatically mind used here


/* questions statement -
Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1


Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

*/

// [ currenct point ] - [ base point ] = [ ans point ] 
// they both are same  = count -> 1


class Solution {
    private:
    void dfs ( int row , int col , vector<vector<int>> &grid , vector<vector<int>> &vis , 
    vector<pair<int,int>> &ans , int baseRow , int baseCol){
        
        // mark visted and push into the vector 2-D matrix
        vis[row][col] = 1;
        ans.push_back({row - baseRow , col - baseCol});
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = { -1 , 0 ,1,0};
        int delCol[] = { 0 , -1, 0 ,1};
        for( int i = 0 ; i<4 ; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >=0 && nrow<n && ncol >=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ){
                dfs( nrow, ncol , grid , vis, ans , baseRow , baseCol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>> st;
        
        for( int i = 0 ; i<n ; i++){
            for( int j =  0 ; j<m ; j++){
                if( !vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> store;
                    dfs( i , j , grid , vis ,store,i , j);
                    st.insert(store);
                }
            }
        }
        return st.size();
    }
};
