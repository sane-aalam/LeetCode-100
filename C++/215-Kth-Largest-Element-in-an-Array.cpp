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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;

        for(int i = 0; i<nums.size(); i++){
            minHeap.push(nums[i]);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};