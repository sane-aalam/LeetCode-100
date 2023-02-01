class Solution {
public:
    int search(vector<int>& nums, int target) {
    
    	// let's think key = target value
       int key = target;
        
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end-start)/2;
        
        while(start <= end){
            // if arr value is equal to key value
            if(nums[mid] == key){
                return mid;
            // if arr value is less then age jana hay
            }else if(nums[mid]<key){
                start = mid + 1;
            // if arr value is grether then we can go piche
            }else{
                end = mid - 1;
            }
            
            mid = start + (end-start)/2;
        }
        // if element is not present in the array then return -1 
        return -1;
    }
};
