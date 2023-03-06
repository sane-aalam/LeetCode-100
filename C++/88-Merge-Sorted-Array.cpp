class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> nums(m + n, 0); // make a new vector with size (m+n)
        int i = 0; // pointer to keep track for num1
		int j = 0; // pointer to keep track for num2
		int k = 0; // pointer to keep track for new vector nums
		
		// if number of elements in nums2 is 0, then just return since there's nothing to do
        if (n == 0)
            return;
		
		// while both the pointers are within the limits
        while (i < m && j < n)
        {
            // element of num1 is smaller, we will insert that in nums
            if (nums1[i] < nums2[j])
                nums[k++] = nums1[i++];
			// element of num2 is smaller, we will insert that in nums
            else
                nums[k++] = nums2[j++];
        }

		// now which ever array has pointer still within its limits needs to be inserted into nums 
        while (i < m)
            nums[k++] = nums1[i++];
        while (j < n)
            nums[k++] = nums2[j++];

		// now copy the new vector to the nums1
        nums1 = nums;
        
    }
};
