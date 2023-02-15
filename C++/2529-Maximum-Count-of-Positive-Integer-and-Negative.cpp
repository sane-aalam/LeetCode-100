
//Input: nums = [-2,-1,-1,1,2,3]
//Output: 3
//Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.


class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p = 0, n = 0;
        for(int i : nums) {
            if(i > 0) p ++;
            else if(i < 0) n++;
        }
        return max(n, p);
    }
};
