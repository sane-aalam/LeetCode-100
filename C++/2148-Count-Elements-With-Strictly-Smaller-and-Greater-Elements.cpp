// 2148. Count Elements With Strictly Smaller and Greater Elements 

// Approach simple hai
// - findout the maximum Element and miniElemtn
// - apply striclly smaller and greater array element then unhe element ko count kar lo

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int miniElement = INT_MAX; 
        int maxiElement = INT_MIN;

        for(int i = 0; i < n; i++){
            miniElement = min(miniElement,nums[i]);
            maxiElement = max(maxiElement,nums[i]);
        }

        for(int i = 0; i<n; i++){
            // striclly smaller and greater greather then count++
            if(nums[i]> miniElement && nums[i] < maxiElement){
                count = count +1;
            }
        }
        return count;
    }
};