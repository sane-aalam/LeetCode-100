// 283. Move 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         // code here
	    int non_zero_element = 0;
	    int n =  nums.size();

	    for(int i = 0; i<n; i++){
	        if(nums[i]!=0){
	            swap(nums[i],nums[non_zero_element]);
	            non_zero_element++;
	        }
	    }
    }
};