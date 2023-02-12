
// first weekly constest questions : 12 Feb - 2023 
// today i gave my first contest LEETCODE and solve two quesions


// Input: nums = [7,52,2,4]
// Output: 596
// Explanation: Before performing any operation, nums is [7,52,2,4] and concatenation value is 0.
//  - In the first operation:
// We pick the first element, 7, and the last element, 4.
// Their concatenation is 74, and we add it to the concatenation value, so it becomes equal to 74.
// Then we delete them from nums, so nums becomes equal to [52,2].
//  - In the second operation:
// We pick the first element, 52, and the last element, 2.
// Their concatenation is 522, and we add it to the concatenation value, so it becomes equal to 596.
// Then we delete them from the nums, so nums becomes empty.
// Since the concatenation value is 596 so the answer is 596.


// algorithm used here - Two pointer algoritm

// - set the both variable with start and end
// - add both first and last index value using string 
// - convert this string into the numberical value



class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long n=nums.size();
        long long ans=0;
        
        if(n==1) return nums[0];
        
        long long i=0;
        long long j=n-1;
        
        while(i<j){
            string s=to_string(nums[i]) + to_string(nums[j]);
            // string to interget convert 
            ans += stoi(s);
            i++;
            j--;
        }
        
        if(i==j) 
            ans += nums[i];
        return ans;
    }
};

