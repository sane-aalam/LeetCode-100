// 852. Peak Index in a Mountain Array

// base on the binary search 
    // 1. create graphs indexing (linear)
    // 2. according to index ( -1,0,1,2) to we can move
    // 3. must try run 


// Tc - 0(longN)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start = 0;
        int end = arr.size() - 1;

        int mid = start + (end - start)/2;

        while(start<end){
            if(arr[mid] < arr[mid+1]){
                start = mid + 1;
            }else{
                end = mid;
            }
             mid = start + (end - start)/2;
        }
        return start;
    }
};