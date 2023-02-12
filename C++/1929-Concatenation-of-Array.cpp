

// we want to add same array again,

// 1. we are doing noting 
// 2. just traversal array 
// 3. push every element into the array again
// 4. return array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        const int n = nums.size();

        for (int i = 0; i < n; ++i)
            nums.push_back(nums[i]);

        return nums;
    }
};
