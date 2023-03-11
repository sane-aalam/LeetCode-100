class Solution {
public:
    void deleteNode(ListNode* node) {
        // checkout the is already single node 
        if(node == nullptr) delete node;
        // the node value of given node and next node of given node 
        swap(node->val,node->next->val);

        ListNode * temp2 = node->next;
        node->next = node->next->next;
        delete temp2;
    }
};
