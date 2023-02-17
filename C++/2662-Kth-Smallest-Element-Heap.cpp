
/*
 Approach 1 : use sorting + return arr[k-1]
 Approach 2 : use Heap data structure but which one heap
              : use max Heap - Kth + smallest
              : use min Heap - kth + largest

 Tc = O(logK) because kth smallest are processing 
 remeaing element we are not taking ):

*/

class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue <int> maxHeap;

        for(int i = 0; i<nums.size(); i++){
            maxHeap.push(nums[i]);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};