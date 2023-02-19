/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
notes -
1. use inorder traversal because it always give sorted order format
2. we want to minimum differece 
   arr[i] - arr[i-1]
   arr[1] - arr[0]
   remove 
3. store the index value
4. compleixty - 0(N) TC and Sc 

points- there is no need to sort the array, if we use postorder,preorder,levelorder algortm
*/

class Solution {
private:
   void inorder(TreeNode* root, vector<int>& arr){
       if(root == nullptr) 
         return;
       inorder(root->left,arr);
       arr.push_back(root->val);
       inorder(root->right,arr);
   }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        int ans = INT_MAX;

        for(int i = 1; i< arr.size(); i++){
            ans = min(ans,abs(arr[i] - arr[i-1]));
        }
        return ans;
    }
};
