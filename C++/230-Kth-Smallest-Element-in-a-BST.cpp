// 230. Kth Smallest Element in a BST (Medium)

// Given the root of a binary search tree, and an integer k, 
// return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Input: root = [3,1,4,null,2], k = 1
// Output: 1


// 1 : solution using level order traversal + sorting ✔

int kthSmallest(TreeNode* root, int k) {
    if(!root){return 0;}
    vector<int>v;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        v.push_back(root->val);
        if(root->left){q.push(root->left);}
        if(root->right){q.push(root->right);}
    }
    sort(v.begin(), v.end());
    if(v.size()<k){return 0;}
    return v[k-1];
}



// 2 : solution using priority_queue ✔

class Solution {
private:
    // inorder recursive code (DFS)
    void inorderTraversal(TreeNode* root, vector<int>& resultArray){
        if(root == nullptr) 
             return;

        inorderTraversal(root->left,resultArray);
        resultArray.push_back(root->val);
        inorderTraversal(root->right,resultArray);
    }

public:
    int kthSmallest(TreeNode* root, int k) {

        vector<int> resultArray;
        inorderTraversal(root,resultArray);

        int size = resultArray.size();
        priority_queue<int> q;
        for(int index  = 0; index < size; index++){
            q.push(resultArray[index]);
            if(q.size() > k){
                q.pop();
            }
        }
        int value = q.top();
        return value;
    }
};


// Complexity
// Time complexity:
// O(n) - where n is the number of nodes in the BST,
//  as each node is visited only once.

// Space complexity:
// O(h) - where h is the height of the BST from the number of nodes 
// stored in the call stack during the recursive calls.