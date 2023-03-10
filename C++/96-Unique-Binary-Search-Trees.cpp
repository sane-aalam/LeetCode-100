class Solution {
public:
   // recursive code in Binary search Tree
    int numTrees(int n) {
          int result=0;
        if(n==1 || n==0)
            return 1;
        for(int i=0;i<n;i++)
            result+=numTrees(i)*numTrees(n-i-1);
        return result;
    }

    // convert recusive code into the memorization ):
    /*
    - create 1D array
    - store the value of every resursive call
    - if this value is already store into the dp array 
      you can use this value there is no need to re-compute the value 
    */
    int dp[20];
    int solve(int n) {
        if(n <= 1) 
           return 1;
        if(dp[n]!= -1) 
          return dp[n];

        int ans = 0;
        for(int i=1; i <= n; i++) {
            ans += solve(i-1) * solve(n-i);
        }
        return dp[n] = ans;
    }
    // start your code
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(n);
        return ans;
    }
};
