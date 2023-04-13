//
//arr[] = 1,1,2,2,3,4,4

// basic of the xor operator
//1 ^ 1 = 0
//2 ^ 2 = 0 
//3 ^ 0 = 3
//4 ^ 4 = 0

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int xorvalue = 0;
        for(int i = 0; i<nums.size(); i++){
            xorvalue = xorvalue ^ nums[i];
        }
        return xorvalue;
    }

