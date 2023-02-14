
// convert sorted list into the array
// apply sorted array to BST createion same patterns


class Solution {
private:
 TreeNode* BST(vector<int>& v, int l, int r) {

        // base condtions 
        if (l > r) return NULL;
        int mid = (l + r) / 2;

        TreeNode* root = new TreeNode(v[mid]);
        root->left = BST(v, l, mid - 1);
        root->right = BST(v, mid + 1, r);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }

        return BST(v,0,v.size()-1);
    }
};
