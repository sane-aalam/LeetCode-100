/*              Rotting Oranges Approach used ))::

            - We need to BFS graph traversal algorithm, because adjacent 
              fresh oranges are to be rotten level by level. DFS won't work.
            - Firstly, store indexes {i, j} with 0 time instant of the initally
              rotten oranges in the queue. {{i, j}, 0}
              
            - Then do standard BFS algo.
            - Take out each one by one from the queue, check for its
              up, down, left and right and modify fresh oranges to rotten and 
              push them into queue, while increasing time by 1.
              
            - Initially count 1s in the array as freshCount, and reduce this by one
              everytime we rot an orange.
            - Finally, freshCount should become 0, so return the time, 
              otherwise, return -1, as all fresh oranges could not be rotten.

              TC= O(NxM);
              SC = O(NxM);
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // size of the matrix
        int n = grid.size();
        int m = grid[0].size();

        // visted matrix 
        vector<vector<int>>vis(n,vector<int>(m,0));

        // i don't want to change origanl data so create a matrix copy
        vector<vector<int>>& ans = grid;

        // crate queue data structure with ((row, col), time)        
        queue<pair<pair<int,int>,int>>q;
        
        // push into the queue which one is rottern oranges
        for(int row = 0; row< n; row++){
            for(int col = 0; col < m ; col++){
                if(ans[row][col] == 2){
                    q.push({{row,col},0});
                    vis[row][col] = 2;
                }
            }
        }

         int MiniTime = 0;
            while(!q.empty()){
                auto row=q.front().first.first;
                auto col=q.front().first.second;
                int time=q.front().second;
                q.pop();
    
                MiniTime=max(MiniTime,time);
                
                // create for 4-directions move->
                int delrow[]={-1,0,1,0};
                int delcol[]={0,1,0,-1};

                for(int i=0;i<4;i++){
                    // using this patter we can find out the new row and new colum index
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];

                    // --- 3 condtions would be checked here ----
                    // 1-> valid range - matrix range ( not out of the boundaries )
                    // 2-> if it is not already rottern oranges
                    // 3-> if it fresh oranges
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&grid[nrow][ncol]==1 && ans[nrow][ncol]!=2 ){
                        ans[nrow][ncol]=2;
                        q.push({{nrow,ncol},time+1});
                    }
                }
        }
        // if Return the minimum number of minutes that must elapse until no cell has a fresh orange. 

        // If this is impossible, return -1.
        for(int i=0;i<n;i++ ){
                for(int j=0;j<m;j++) {
                    if(ans[i][j]==1){
                        return -1;
                    }
                }
            }
        return MiniTime;
    }
};
















