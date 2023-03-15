/* 
64. Minimum Path Sum
we want to minimum path sum.
according to question - all the ways ( all the possible way we wil find out )
which data stucture help me to find out the all ways

defentilly - recursion data structure 
process to write recursive code :
1. express everthing in terms of index ( i,j)
2. do all the possilbe ways
3. according to questions ( add - min , max, longest, shorest )
4

convert recursive code + memorization
1. create a matrix using changable variable
2. store the recusrive call into the dp matrix
3. whenever there is call, check this call value is already stored into the dp matrix 
4. don't think too much use it right now 
*/

class Solution {
private:
  int solve(int i, int j, vector<vector<int>> & grid, vector<vector<int>> & dp){

      // if you are able to reach arr[0][0] this column
      if(i == 0 && j == 0)
      return grid[0][0];

      if(i < 0 || j < 0)
      return 1e9;

      if(dp[i][j] != -1)
      return dp[i][j];

      int up = grid[i][j] + solve(i-1,j,grid,dp);
      int left = grid[i][j] + solve(i,j-1,grid,dp);

      int ans = min(up,left);
      return dp[i][j] = ans;
  }
  
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};
