class Solution {
private:
   int countsubsetsum(vector<int>A ,int sum,int n){
       
      int dp[n+1][sum+1];
      for(int i =0;i<n+1;i++){
        dp[i][0] = 1;
    }
    for (int j =1;j<sum+1;j++){
        dp[0][j] = 0;
    }
    
    for (int i =1;i<n+1;i++){
        for (int j=0;j<sum+1;j++){
            if (A[i-1]<=j){
                dp[i][j] =  dp[i-1][j-A[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
   }
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
         //Your code here
       int sum =0;
       int n = nums.size();
       
       for (int i =0;i<n;i++){
           sum+=nums[i];
       }
       
       /*
            Solutions : 
            Let sum of subset 1 be s1 and subset 2 with s2
            s1 - s2 = diff (given)
            s1 + s2=sum of array (logical)
            Therefore adding both eq we get :
            2s1= diff + sum of array
            s1= (diff + sum of array)/2;
            Problem reduces to find no of subsets with given sum

            NOTES :
            Even Sum = you can find the equal
            Odd sum = then you can not find equal value         
    
    */
       if(target>sum)
           return 0;
           
       if((target+sum)%2!=0)
           return 0;
           
       sum  =  (sum - target)/2;
       return countsubsetsum(nums,sum,n);
    }
};
