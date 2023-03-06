/* shorted path - think about first of Dijstra Algoritm
 - there are three way to use Dijstra Algorithm - use queue and use priority queue and use set
 - for this questions we are using unit length 
  --- you can use simple bfs algoritm
  1 ) simple take visisted array and queue 
  2 ) go the 8-direction 
  3 ) condtions - it is valid range + it is not visited alerady + it is zero
  4 ) mark visted and push into the queue 

  5) at any case - you are able to reach 

  source to destination means ->

       if(row == n-1 && col == m-1){
            return min(path,ans);
    }

    Last - if you are not able to reach source to destination 
    no need to do this, do this,
    simple return -1;
    according to the questions!

    Thank you!
    
Time Complexity: O(8 x n x n) as we can visit at max each element of the grid and for each element we can search for path in its 8 directions
Space Complexity: O(n x n) as we can have all the elements in the queue
*/




class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // size of the grid row wise and colum wise 
        int n = grid.size();
        int m = grid[0].size();

        // Edages case - what is scouce node is not zero and destination node is not zero 
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        // push into the queue 
        // mark visted this particular cell 
        q.push({1,{0,0}});
        vis[0][0] = 1;

        int ans = INT_MAX;

        while(!q.empty()){
            int path = q.front().first;
            int row  = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            // if scouce are equal to distincation then return -
            // The length of a clear path is the number of visited cells of this path.
            if(row == n-1 && col == m-1){
                return min(path,ans);
            }

            // Traveral the 8-directions
            //up down left right uprd drdl upld dldl
            int delrow[8] = {-1,1,0,0,-1, 1, -1, 1};
            int delcol[8] = {0,0,-1,1, 1, 1, -1, -1}; 

            for(int i = 0; i<8; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if(newrow >= 0 && newrow <n && newcol >= 0 && newcol < m && 
                !vis[newrow][newcol] && grid[newrow][newcol] == 0){
                    vis[newrow][newcol] = 1;
                    q.push({path+1,{newrow,newcol}});
                }
            }
        }
        return -1;
    }
};

//Night : 3:57 solved this wonderful questions 
// 07 March 2023 
