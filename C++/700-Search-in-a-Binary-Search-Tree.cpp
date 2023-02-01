// Solution 01 : store inorder + using binary search (very easy to understand)
//             : you can dry run for your understaning but in this case we are using space complexity for storing nodes into the array 


// solution 02
// Using Recursion.
// Here we have 4 possible cases:
// if(root== NULL) means we didn稚 find the element in the tree, so we値l return null.
// if(root->val == val) we find our root, simply return it.
// if(root->val > val) as our current value is greater & in BST lift side we値l have smaller values, so we値l search for the left tree only.
// if(root->val < val) here current value is less so we値l simply search on the right tree.

// Time complexity: O(n), worst case it can have 1node in every stage!


// solution - 03 using itrative solutons ( using loop )


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root== NULL) 
            return NULL;

        if(root->val == val) 
            return root;

        if(root->val > val) 
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
