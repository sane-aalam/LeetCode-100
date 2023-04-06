

class Solution {
public:
    int reverse(int x) {
        
       int reverseNumber = 0;

        while(x != 0){

             if(reverseNumber > INT_MAX/10 || reverseNumber < INT_MIN/10) 
                //need to check this first 
                // (if input would overflow in next line) and if the value calculated will overflow
                return 0;

            int lastdigits = x % 10;
            reverseNumber = reverseNumber * 10 + lastdigits;
            x = x / 10;
        }
        return reverseNumber;
    }
};
