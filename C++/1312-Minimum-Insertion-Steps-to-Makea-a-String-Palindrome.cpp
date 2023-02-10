
       /*    LCS :
            1.  palidrome is subset of the longest common subsquence ( always remember )

2.  in this questions we want to find out the palidrome 
using minimum insertion step to make a string plaindrome

how ?
you know how to get longest palindrome subsqucne using LCS  -
  you are give a string X
	you will find string second Y using reverse of the given string 
	after this,
	now we have two string string X and string Y
	then we will find out the LCS 
	
	LPS = length of X string + length of Y sting - LCS(x,y);
	
	can i use LPS ?
	because we want palidrome using minimum
	i can ?
	
	so firstlly  we will find out the LPS
	
1312. Minimum Insertion Steps to Make a String Palindrome = length of the sting - LPS
1313. MInimum deletion Steps to Make a String Palindrome = length of the sting - LPS
        */
        
class Solution {
public:
    int LCS(string s)
    {
        string r = s; // initialising r to s;
        
        reverse(r.begin(),r.end()); // reverse string for finding Longest Palindromic Subsequence
        
        //ideally both length are same
        int m = s.length(); // length of s;
        int n = r.length(); // lenght of r
        
        int t[m+1][n+1]; // matrix for memoization
        
        for(int i= 0; i<m+1; ++i) {
            for(int j = 0; j<n+1; ++j){
                if(i == 0 || j == 0)    // initialising first row and first column to zero
                    t[i][j] = 0;        
            }
        }
        
        for(int i = 1;i< m+1; ++i) {
            for(int j = 1; j<n+1; ++j){
                if(s[i-1] == r[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                    else
                        t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
         // string length - lPS will give no of minimum insertions  
        // we have to find out single character pair
        return s.length() - t[m][n];

    }
    
public:
    int minInsertions(string s) {
        return LCS(s);
    }
};
