 */
 
 SAME patterns questions
 
 1. inorder to BST
 2. array to BST
 3. sorted array to BST
 4. binary tree to BST
 5. merge two BST 
 6. normal BST to balaced BST  
 
 */
 
 
 
 
 
class Solution {
private:
    TreeNode* createBST(int start , int end, vector<int>&nums){
        if(start>end) return NULL;

        int mid = (start+ end)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        
        // root of left creation
        root->left = createBST(start,mid-1,nums);
        //  root of right creation
        root->right = createBST(mid+1,end, nums);
        // return complete bst
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int startIndex = 0;
        int endIndex = nums.size() - 1;
        return createBST(startIndex,endIndex,nums);
    }
};
