class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        //initialization base condition

        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if( i == 0 ){
                    dp[i][j] == 0;
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        // recusive code convert into the iterative code - CHOICE DIAGRAM 
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                // both string char are same then we will check for remeaning strings
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
