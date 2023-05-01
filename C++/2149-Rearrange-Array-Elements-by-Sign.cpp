//2149. Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        // set the two variable
        int positive = 0;
        int negative = 1;
        // because output result me - positive element store in 0 index 
                                // - negative element store in 1 index value

        for(int i = 0; i<n; i++){
            if(nums[i] < 0){
                result[negative] = nums[i];
                negative = negative + 2;
            }
            else{
                result[positive] = nums[i];
                positive = positive + 2;
            }
        }
        return result;
    }
};
