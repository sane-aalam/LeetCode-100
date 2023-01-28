
// Time Complexity - 0(n)
// Space Complexity - 0(n)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        // if root is null pointer then return zero:
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        int level = 0; 
        q.push(root);
        while(!q.empty()){
           int size = q.size();

           while(size --){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
           }
           level = level + 1;
        }
        return level;
    }
};