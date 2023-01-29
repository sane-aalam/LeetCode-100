

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
--------------------------Right && Left side view ( same pattern question )--------------------

---------right side view (Method) ----------

according to question,
- we clear see the last of node of every level is my node( solution node) right view of the tree
( BFS )
- we can use traversal technique
- we can use level order traversal (( yes )) but complexity increase because we are storing every node in queue but we want only the last nodes,
- we can use level order traversal but remember the complexity

( DFS )
 so we use DFS algorithm,preorder!
 go every level then check array size of level, both are same then store the value
 calling- first we want to last node ( right side node ) 
 we are calling - first right side then left side
 
 thank you!
 
 tc = o(N)
 sc = o(N)
 

*/

class Solution {
private:
    void rightSide(TreeNode* root, int level, vector<int>&arr){
        if(root == nullptr) return;

        if(level == arr.size()){
            arr.push_back(root->val);
        }

        rightSide(root->right, level+1, arr);
        rightSide(root->left, level+1, arr);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        int level = 0;
        rightSide(root,level,arr);

        return arr;
    }
};


//-----------left side view of binary tree----------------


//1) let's try level order traversal algorithm 

vector<int> leftView(Node *root)
{
   // Your code here
     vector<int> res;
   if(root == NULL)
        return res;

   queue<Node *> q;
   q.push(root);
   while(!q.empty()) {
       int cnt = q.size();
       for(int i=0; i<cnt; ++i) {
           Node *n = q.front();
           q.pop();
           if(i == 0)
                res.push_back(n->data);
           if(n->left)
                q.push(n->left);
           if(n->right)
                q.push(n->right);
       }
   }
   return res;
}









