/* Optimised (Using Dijkstra) : 
In this particular problem,

in order to solve this problem-
we need to understand the mapping algoritm ):
when you see - KEYWORDS - path,shorested,minimum, 
which algoritm come into the your mind - offcosue ! Dijstra Algortim

- create the min heap 
-  create the differece matrix ( dijstra algoritm we create distance ) 
   but here we want to difference not distance 
- find out the  maximum absolute difference of 2 in consecutive cells.
  old cell and new cell as effort
- if newEffort smaller privouslly we have privously difference findout the 
  old Diffece = newdiffect ( it is smaller )
	
- any chance you have reach source to destination ( end of the cell )
  return diff;

*/


/* step by step
 
Start by creating a queue that stores the distance-node pairs in the form {dist,(row, col)} 
and a dist matrix with each cell initialized with a very large number ( to indicate that they’re unvisited initially) and the source cell marked as ‘0’.
We push the source cell to the queue along with its distance which is also 0.
Pop the element at the front of the queue and look out for its adjacent nodes (left, right, bottom, and top cell). Also, 
\for each cell, check the validity of the cell if it lies within the limits of the matrix or not.
If the current difference value of a cell from its parent is better than the previous difference indicated by the distance matrix, 
we update the difference in the matrix and push it into the queue along with cell coordinates.
A cell with a lower difference value would be at the front of the queue as opposed to a node with a higher difference. 
The only difference between this problem and Dijkstra’s Standard problem is that there we used to update the value of the distance of a node from the source and here we update the absolute difference of a node from its parent.
We repeat the above three steps until the queue becomes empty or until we encounter the destination node.
Return the calculated difference and stop the algorithm from reaching the destination node. If the queue becomes empty and 
we don’t encounter the destination node, return ‘0’ indicating there’s no path from source to destination.
Here’s a quick demonstration of the Algorithm’s 1st iteration ( all the further iterations would be done in a similar 

*/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

         // ( difference,row,col);
         priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;

        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> absDiff(n,vector<int>(m,INT_MAX));
        // starting me we have to start with source row and col- diffeence it;s 0
        q.push({0,{0,0}});
        absDiff[0][0] = 0;
        
        while(!q.empty()){
            int diff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            
            // by chane we will reach source to destination with minimum effort
            if(row == n-1 && col == m-1){
                return diff;
            }
            
            // we want to 4-directions 
            int delrow[] = {-1,0,1,0};
            int delcol[]  = {0,1,0,-1};
            
            // go the 4-directions- go the up-right-bottom-left
            for(int i =0; i<4; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m){
                    int effort = max(abs(heights[row][col]- heights[newrow][newcol]),diff);
                    if(effort <absDiff[newrow][newcol]){
                        absDiff[newrow][newcol] = effort;
                        q.push({effort,{newrow,newcol}});
                    }
                }
            }
        }
        return 0;
    }
};
