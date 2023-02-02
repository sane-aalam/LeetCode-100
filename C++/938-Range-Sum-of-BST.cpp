

// simple - we are using BFS 
// sum all the nodes which are greater and lesser than node < Low and Hight > 

// TC - 0(n)
// sC - 0(N)


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            root=q.front();
            q.pop();

            if(root->val>=low && root->val<=high){
                sum+=root->val;
            }

            if(root->left){q.push(root->left);}
            if(root->right){q.push(root->right);}
        }
        return sum;
    }
}; 
