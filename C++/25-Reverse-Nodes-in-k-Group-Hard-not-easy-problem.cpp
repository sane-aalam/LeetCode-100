/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 Algorithtm used to solve this problem ::
 

 1 - if you have already solve revese linked list problem, it will be very for you
 2 - Approach simple hay 
   reverse first K nodes
   then call for next k nodes using recursion 
   return prev 

 3- add one more eadges case :
	cursor pointer we can add if currsor pointer is equal to nullptr 
	we can return head 
	then call for next recursive K nodes 

*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
              
    if(head==NULL)
        return NULL;

    // next call for head-next 
    // we will be sending new head here 
    ListNode* cursor = head;
    for(int i = 0; i < k; i++){
         if(cursor == nullptr) 
             return head;
         cursor = cursor->next;
    }

    //reverse 1st k nodes
    ListNode* forward=NULL;
    ListNode* prev=NULL;
    ListNode* curr=head;
    int cnt=0;

    while(curr!=NULL && cnt<k ){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
    }
    // baki ka recursion dekh rahra hay
    head->next=reverseKGroup(forward,k);
    return prev;
    }
};
       
