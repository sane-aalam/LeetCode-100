
/* Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

*/


// Intuition - 1

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> v1;
        vector<int> v2;

        for(int i = 0; i<n; i++){
            v1.push_back(nums[i]);
        }

        int totalsize = 2 * n ;
        for(int i =n; i<totalsize ; i++){
            v2.push_back(nums[i]);
        }

        vector<int> result;
        for(int i = 0; i<n; i++){
            result.push_back(v1[i]);
            result.push_back(v2[i]);
        }
        return result;
    }
};

// Intuition - 2
// Simple taverse from 0 to n and push i,i+n as adjacent elemnts.

// Approach
// Complexity
// Time complexity:O(n)
// Space complexity:O(1)  not taking answer vector

class Solution {
public:
    vector<int> shuffle(vector<int>& arr, int n) {
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(arr[i]);
            ans.push_back(arr[i+n]);
        }
        return ans;
    }
};


