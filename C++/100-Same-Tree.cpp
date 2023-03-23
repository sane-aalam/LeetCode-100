 
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
       // if both of tree is null then return true
       if(p == nullptr and q == nullptr) 
	        return true;
       if(p == nullptr  and q != nullptr) return false;
       if(p != nullptr and q == nullptr) return false;

       bool left = isSameTree(p->left,q->left);
       bool right = isSameTree(p->right,q->right);

       bool value = (p->val == q->val);
       
        if(left && right && value) // all are true means all the equal
        {
         return true;
        } else {
            return false;
        }
    }
}; 
