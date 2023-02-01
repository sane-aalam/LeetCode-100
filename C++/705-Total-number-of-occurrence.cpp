
// - https://github.com/sane-aalam/leetcode-solved

class Solution {
public:
    int firstpostion(vector<int>&arr, int key){
        int start = 0;
        int end = arr.size()-1;
        int mid = start + (end - start)/2;
        int first = -1;
        
        while(start<=end){
            if(arr[mid] == key){
                first = mid;
                end = mid - 1;
            }else if(arr[mid] < key){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return first;
    }
    int lastpostion(vector<int>&arr, int key){
        int start = 0;
        int end = arr.size()-1;
        int mid = start + (end - start)/2;
        int last = -1;
        
        while(start<=end){
            if(arr[mid] == key){
                last = mid;
                start = mid + 1;
            }else if(arr[mid] < key){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      
        int result1 = firstpostion(nums,target);
        int result2 = lastpostion(nums,target);
        
        /*	
        	N = 7, X = 2
			Arr[] = {1, 1, 2, 2, 2, 2, 3}
			Output: 4
				
		*/
        
        // easy - you can understand ( right = 5, left = 2 )
        // so ( right - left + 1 => 5 - 2 + 1 = 4 )  
        
        // correct way to find out the total number of occurrence-
        
        int totalNumberOfOccurrence = result2 - result1 + 1;
        return totalNumberOfOccurrence;
    }
};
