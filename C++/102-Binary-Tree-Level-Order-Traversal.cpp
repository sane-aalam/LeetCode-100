//	Level Order Travesal problem 
//    flow of solving this problem  - 
//    a) in this order , you can use queue because queue follow FiFo concept 
//		( means jo level pahle aayge wo pahle print hota jayga )
//    b) first of all push root node for accessing left and right node
//    c) then pop the element but 
//    d) does pop element(3) have left node?/ right node?
//    e) if have then push into the queue 
//    g) same process continue until queue empty()


// Tc - o(N) and SC = o(N)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> Error;
        
        if(root == nullptr) 
            return Error;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
           int size = q.size();
           vector<int> dost;

           while(size --){
                TreeNode * temp = q.front(); 
                q.pop();
                dost.push_back(temp->val);
                if(temp->left != nullptr) 
                 q.push(temp->left);
                if(temp->right != nullptr) 
                 q.push(temp->right);
           }

         Error.push_back(dost);
        }
        return Error;
    }
};

