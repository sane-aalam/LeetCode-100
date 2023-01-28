
/*

1.Create a vector Inorder to store the nodes. 
2. 	Traverse the tree in such a way that the nodes stored in the vector are in ascending order i.e. Inorder Traversal. 
Inorder: [ 1, 2, 3, 4 ]						
3. 	Then use this vector of nodes to find the root node of the balanced BST.
4. 	The newRoot node will be mid element of the array;
5. 	int start = 0
6. 	int end = arr.size() - 1;
find out middle index according middle index you can create node in BST
newRoot= Inorder[mid]=2							
5. Then recursively add the mid of first half to the left of the tree.
newRoot->left=1							
6. And the mid of second half to the right 

*/

// TC = 0(N) && SC = 0(N)

class Solution {
private:
    // we have inorder terversal code because it provide always sorted array
    void inorder(TreeNode* root, vector<int>& arr){
        if(root == nullptr) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    // convert sorted array into Binary search tree
    TreeNode* createBST(int start , int end, vector<int>&arr){
        if(start>end)return NULL;
        // find out the middle index 
        int mid = (start+end)/2;
        TreeNode * root = new TreeNode(arr[mid]);
        root->left = createBST(start,mid-1, arr);
        root->right = createBST(mid+1,end,arr);
        return root; // at the last you can return answer
    }

// start code 
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);

        // for create a complete binary search tree we will taking this index array of start and array of end ):
        int start = 0;
        int end = arr.size() -1;

       return createBST(start,end,arr);
    }
};