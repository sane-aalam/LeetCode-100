// 62. Unique Paths - Leetcode

/* Process to solve dynamic Progamming Questions 
- understand the problem statement // summary of the questions ( Hint - given )
- try to think which data structure we can use solve this problems
- dry run 
- recursive code + memorization + top down approach 
- space and time complexity 
 */

// Case 1 : Recursive solutions 
// it will provide TLE 
class Solution {
private:
   int solve(int i, int j){
       if(i == 0 && j == 0) return 1;
       if(i < 0 || j < 0) return 0;
       // we are using reverse method (n-1,m-1) to (0,0)
       int up = solve(i-1,j);
       int left = solve(i,j-1);
       return up + left;
   }
public:
    int uniquePaths(int m, int n) {
       int result = solve(m-1,n-1);
       return result;
    }
};

// case 2 :  Memoriztion solution - works 100%
// if you are able to indentify overlapping subproblems use this appraoch

class Solution {
private:
    int allWays(int i, int j, vector<vector<int>> & dp ){
        // base condtion
        // when you are able to reach source to desination
        if(i == 0 && j == 0)
            return 1;
        // if anyone index gonning to out of boundary then you are not able to reach to source to desitnation 
        if(i < 0 || j < 0) 
            return 0;
        
        // overlapping condtion stop - we have already this value use this value 
        if(dp[i][j] != -1) 
            return dp[i][j];

        int up = allWays(i-1,j,dp);
        int left = allWays(i,j-1,dp);
        int sum = up + left;
        return dp[i][j] = sum;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int result =  allWays(m-1,n-1,dp);
        return result;
    }
};

// Case 3 : Topdown Approach 
class Solution {
public:
    int uniquePaths(int m, int n) {
        // declare the matrix and initialization with help 1 
        vector<vector<int>> dp(m,vector<int>(n,1));
		
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
		// we have dp[i-1][j] + dp[i][j-1] paths to reach at ith row and jth column
        // we will add the possilbe way to reach source to destination 
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
