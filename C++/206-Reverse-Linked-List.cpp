
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode;
        ListNode *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
      return prevNode;
    }
};
