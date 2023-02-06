

// 876. Middle of the Linked List

// Slow and fase alogrithm

//slow = run one step
//fast = run two step

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(head == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
