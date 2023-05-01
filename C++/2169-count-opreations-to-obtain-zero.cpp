/*
Leetcode - 2169. Count Operations to Obtain Zero
Link - https://leetcode.com/problems/count-operations-to-obtain-zero/description/

Input: num1 = 10, num2 = 10
Output: 1
Explanation: 
- Operation 1: num1 = 10, num2 = 10. Since num1 == num2, we subtract num2 from num1 and get num1 = 10 - 10 = 0.
Now num1 = 0 and num2 = 10. Since num1 == 0, we are done.
So the total number of operations required is 1.

Appraoch - 
1- we have to numbers - num1 and num2
2- if num1 is greater then num2 then num1 - num2 = num1 
3- if num2 is greater then num1 then num2 - num1 = num2 
4- we want to calculate opreations make to zero 
   we will count the opreations ( substration steps )

*/

class Solution {
public:
    int countOperations(int num1, int num2) {
       int count = 0;
        while(num1 != 0 && num2 != 0){
            if(num1 <= num2){
                num2 = num2 - num1;
            }else if(num1 >= num2){
                num1 = num1 - num2;
            }
            count = count + 1;
        }
        return count;
    }
};
