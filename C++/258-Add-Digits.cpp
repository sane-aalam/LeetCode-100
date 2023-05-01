
/*

this question is based on the extraction of the digits

*/

class Solution {
public:
    int addDigits(int num) {
        
        while(num>9){
            int sum = 0;
            while(num){
                sum = sum + num % 10;
                num = num / 10;
            }
            // digits sum assign to the num
            num = sum;
        }
       return num;
    }
};

