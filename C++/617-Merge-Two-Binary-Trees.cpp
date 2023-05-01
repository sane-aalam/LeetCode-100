/**
 * Definition for a binary  node.
 * struct Node {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/

// ---------Approach--------------
// 1. both are null reutrun null
// 2. if root1 is null then we want root2 
// 3. if root2 is null then we want root1
// 4. if both are not null then add root1 val of root2 val
// 5. recursive call for left and right ( for every node ) 

// tc = 0(N) 
// sc = 0(N)

class Solution {
public:
    TreeNode* mergeTrees(Node* root1, Node* root2) {
        
        if(root1==nullptr && root2 == nullptr)
            return nullptr;
        
        if(root1 == nullptr) 
            return root2;
        if(root2 == nullptr )
            return root1;
        
        root1->val += root2->val;
        
        root1->left = merges(root1->left,root2->left);
        root1->right = merges(root1->right,root2->right);
        return root1;
    }
};
