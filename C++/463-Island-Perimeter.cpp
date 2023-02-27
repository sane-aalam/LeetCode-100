
/*

 number of instads same problem
 463. Island Perimeter - think like you are solving number of insland problem
 slide vareations 
 
 	1. CASE 
	it is valid range and it is land
	
	2. CASE
	it is not valid range and it is not land 
	
	tc = 0(n*m)
*/

class Solution {
private:
  int dfs(int row, int col, vector<vector<int>> & grid){
      int n = grid.size();
      int m = grid[0].size();

       int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int count = 0;

        for(int k = 0; k<4; k++){
            int newrow = drow[k]+ row;
            int newcol = dcol[k] + col;
            
            // if it is valid range and land 
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1){
                continue;
            // if it is not valid range and not land 
            // increase the counter = count + 1;
            }else{
                count ++;
            }
        }
        // return 4 = 4 parimeter 
        return count;
  }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                // cell contain lands then call dfs and store all possible into the answer variable
                if(grid[row][col] == 1){
                   ans = ans + dfs(row,col,grid); // call dfs 
                //    ans = ans + 4
                //    ans = 4 
                }
            }
        }
        return ans;
    }
};
