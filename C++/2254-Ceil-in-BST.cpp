

/*
    
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

Example 1:

Input:
      5
    /   \
   1     7
    \
     2 
      \
       3
X = 3
Output: 3
Explanation: We find 3 in BST, so ceil
of 3 is 3.
*/


// Appraoch - 1  if key is not equal then we can return big integer value
                //  else key is equal then return simple valu


int findCeil(Node* root, int input) {
   int ceil = -1;
   while(root){
       // if equal then 
       if(root->data  == input ){
           ceil = root->data;
           return ceil;
       }
       if(root->data < input){
           ceil = root->data;
           root = root->right;
       }else{
           ceil = root->data;
           root = root->left;
       }
   }
   return ceil;
}