

//Given an array nums of distinct integers, return all the possible permutations. 
//You can return the answer in any order.


//Example 1:

//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


/*	
	Approach to solve this problem and this type problem - 
	when you see choice and include and not include pattern then think about recursion data structure
	
	in this example 1: we have choice we can inlude and not include 
	
	1) include the element and not include the element
	2) when you are inlcuding the element then think about you are visting the element, you are done! element no need to reapt again! again!
	3) when you are going to back - mark un-visted ( pop the element )
	
	
		CHOICE DIAGRAM + RECURSIVE TREE ( FOR BETTER UNDERSTAND )
		
			Firstly the recursion tree: n options on 1st layer, n - 1 options on 2nd layer ... So, 
			the recursion tree has (n!) nodes.
		
			you can improve - i will try improve now! okay
		
*/



class Solution {
private:
    void FindPermutations(vector<int> nums, vector<int>& arr,vector<vector<int>>&result, int NotReapt[]){

        // if your array size is equal give array size ( when give array is empty then backtrack game apply )
        if(arr.size() == nums.size()){
            result.push_back(arr);
            return;
        }

        // we are traversalling all the nodes
        for(int i = 0; i<nums.size(); i++){
            if(!NotReapt[i]){
                arr.push_back(nums[i]);
                NotReapt[i] = 1;  // mark visited - means I'm done, i'm not doing anything now.
                FindPermutations(nums,arr,result,NotReapt);
                NotReapt[i] = 0; // mark un-visited - when you are going to back mark-false and pop the element
                arr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> arr;

        
        int notVistedContainer[nums.size()];
        for(int i=0 ; i<nums.size() ; i++) 
            notVistedContainer[i]=0;

        FindPermutations(nums,arr,result,notVistedContainer);
        return result;
       }
};
