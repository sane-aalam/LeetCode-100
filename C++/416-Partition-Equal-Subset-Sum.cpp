/* Variation of the 0-1 knapscak || TOP DOWN APRROACH 

 A) create a matrix and installization of matrix
 B) if even 22 = 11 + 11 equal division possible otherwise no division possible
 C) if you have one part ( means you have one sum then simply findout the second sum )
 if present then return true otherwise false;*/

/* DYNAMIC PROGRAMMING */

class Solution {
public:
    bool subset(vector<int>& nums, int sum, int n ){
       int w = sum;
       bool t[n+1][w+1];
       for(int i =0; i<n+1; i++){
           for(int j=0; j<w+1; j++){
               if(i==0){
                   t[i][j] = false;
               }
               if(j==0){
                   t[i][j] = true;
               }
           }
       }
       
       for(int i =1; i<n+1; i++){
           for(int j=1; j<w+1; j++){
              if(nums[i-1]<=j){
                  t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
              }else{
                  t[i][j] = t[i-1][j];
              }
           }
       }
       
      return t[n][w];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum +=nums[i];
        }
        
        if(sum%2 != 0){
            return false;
        }else{
            return subset(nums,sum/2,n);
        }
    }
};
