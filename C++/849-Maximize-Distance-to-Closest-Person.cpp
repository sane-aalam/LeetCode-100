/*
relate this questions to bus )
jab hum baps me jaate to dekhte kaha khaali sets hai 
1- kay kahali seats first me hai - driver ke pass 
2- kya khali middle me hai 
3- kya khali seats piche hai last me hai 
middle sets = hum bhag me divide kar dete hai 

jisme khali jagah hogi wahan hum bath jainge 
tc - 0(n) + 0(n) + 0(n) = 0(N) 

*/

/*
relate this questions to bus )
jab hum baps me jaate to dekhte kaha khaali sets hai 
1- kay kahali seats first me hai - driver ke pass 
2- kya khali middle me hai 
3- kya khali seats piche hai last me hai 
middle sets = hum bhag me divide kar dete hai 
*/


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(); 

        int leftzeros = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(seats[i] == 0){
                count ++;
                leftzeros = max(count,leftzeros);
            }else{
                break;
            }
        }

        // finout the coutinous maximum zeros in the array 
        int middlezeros = 0;
        count = 0;
        for(int i = 0; i<n; i++){
            if(seats[i] == 0){
                count ++;
                middlezeros = max(middlezeros,count);
            }else{
                count = 0;
            }
        }

        int rightzeros = 0;
        count = 0;
        for(int i = n -1; i>=0; i--){
             if(seats[i] == 0){
               count ++;
               rightzeros = max(rightzeros,count);
            }else{
                break;
            }
        }

        // divide two half middle seats
        middlezeros = (middlezeros+1)/2;
        int result1 = max(middlezeros,max(leftzeros,rightzeros));
        return result1;
    }
};
