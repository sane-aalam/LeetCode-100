
// 516. Longest Palindromic Subsequence
// Medium

// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another 
// sequence by deleting some or no elements without changing the 
// order of the remaining elements.


class Solution {
    // LCS function used here
private:
    int longestCommonSubsequence(string s1, string s2){
        
        int n = s1.length();
        int m = s2.length();


        int dp[n+1][m+1];

        // recursive base condtion convert into first row and first column installizations
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }

        // choice diagram

        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
public:
    int longestPalindromeSubseq(string s) {
        
        // create second string to apply LCS method 
        string reverseString="";

        // using for loop reverse string 
        for(int i=s.length()-1;i>=0;i--){
            reverseString.push_back(s[i]);
        }

        /*
        Palindromic is subset of LCS.
        Apply matching algoritm

        Lcs = string1 + string2 + int ( return type )
        Lps = string + ? + int( return type )


        first of all we are trying to string second, 
        first we take same string 1 = not work
        second we take reverse of string 1 = work ( we will find LCS ) -
         we will able to use LcS
        reverse(s.begin(), s.end());

        ------------LPS = LCS( s1, reverse of s1)----------
        */
        return longestCommonSubsequence(s,reverseString);
    }
};
