
//404. Sum of Left Leaves

// recursive solution - use preorder traversal 

class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root,bool flag){
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr && flag == true)
            ans = ans + root->val;
        
       solve(root->left,true);
        solve(root->right,false); 
    
    }
    int sumOfLeftLeaves(TreeNode* root) { 
        bool falg = false;
        solve(root,falg);
        return ans;
    }
};

/*
1. go to the leaf node
2. sum of only left nodes all 
3. if we want to find only left nodes then true for left
4. flase for right 
you can use preorder/postordr/inorder any order tareval 


approach - 2 bfs  )
in order to apply bfs algoritm -
1.  need queue data structure
	2.  apply same bfs algortim change is if 
	    root ka left ka left null and root ka left ka right null hay
		  toh add kar lo ek sum variable me 
3. return sum 
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root == nullptr)
             return 0;

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();

            if(temp->left != nullptr){
                q.push(temp->left);
                if(temp->left->left == nullptr && temp->left->right == nullptr){
                    sum = sum + temp->left->val;
                }
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
        }
        return sum;
    }
};
