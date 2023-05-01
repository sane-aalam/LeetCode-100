
/*
approach - 1 
1 - add the sum of the first string with converting integer
2 - add the sum of second string with converting integer
3-  return sum1 - sum2 with converting charchar value 


*/




class Solution {
public:
    char findTheDifference(string s, string t) {
        
      int sum1 = 0;
      for(int i = 0; i<t.length(); i++){
          sum1 = sum1 + int(t[i]);
      }

      int sum2 = 0;
      for(int i = 0; i<s.length(); i++){
          sum2 = sum2 + int(s[i]);
      }

      if(sum1>sum2){
          return char(sum1-sum2);
      }else{
          return char(sum2-sum1);
      }
    }
};
