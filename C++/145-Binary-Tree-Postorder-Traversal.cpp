class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         
        vector<int> postOrder;
        if(root == NULL) {
            return postOrder;
        }
        
        stack<TreeNode*> st1,st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);

            if(node->right) st1.push(node->right);
        }

        while(!st2.empty()) {
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }
        return postOrder;
    }
};
