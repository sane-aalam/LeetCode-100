

/*

1. easy level order traveal with leftToright variable used 
2. leftToright true then push the data left to right
3. leftToright is false then push the data right to left 
4. after the every level you can change the leftToright direction 
5. if it is ture then 1 otherwise false

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        
        if(root == nullptr) 
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int leftToright = true;
        
        while(!q.empty()){

            int size = q.size();
            vector<int> ans(size);   

           for(int i =0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();  
                /* 
                const age = 26;
                const beverage = age >= 21 ? "Beer" : "Juice";
                console.log(beverage); // "Beer""
                */
                int index = leftToright? i : size-1-i;
                ans[index] = curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            leftToright = !leftToright;
           v.push_back(ans);
        }
        return v;    
    }
};
