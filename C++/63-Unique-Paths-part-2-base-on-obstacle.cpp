

// base condtions : recursive code convert into the memorization 

// 1. if you are able to reach souce to destinations return 1
// 2. if you are gonna to out of the bounary and matrix contains 1 means obstacles return 0
// 3. choice diagram - you can find out the total number of unique way to reach to source to destinations
     
     // Total Number of ways Pattern :
	//dp[i][j] = dp[i+1] [j] + dp[i] [j+1]
	

class Solution {
    int allWays(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) 
            return 1;
        
        // if it is not valid range and not empty cell means contain 0 return 0;
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) 
           return 0;

        // Memorizations : solve the overlapping the problelms 
        if(dp[i][j] != -1) 
           return dp[i][j];

        int u = allWays(i - 1, j, obstacleGrid, dp);
        int l = allWays(i, j - 1, obstacleGrid, dp);

        return dp[i][j] = u + l;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // if the starting row,col contains obstacleGrid
        if(obstacleGrid[0][0] == 1) 
           return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return allWays(m - 1, n - 1, obstacleGrid, dp);
    }
};
