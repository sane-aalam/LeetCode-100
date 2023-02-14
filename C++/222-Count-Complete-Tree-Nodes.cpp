

//1. level order traversal:
//2. store the array element
//3. number of element = ( count complete trees nodes ) ==  array size 
           

//TC = 0(N)
//SC = 0(N)

class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<int> v;
        if(root == nullptr){
            return 0;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        int size = v.size();
        return size;
    }
};
