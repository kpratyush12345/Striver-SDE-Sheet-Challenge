// Optimised Approach - TC: O(n)  SC: O(1)
// -------------------------------------------
// This approach is very similar to the above 3 pointer approach. In the process of reversing, the base operation is 
// manipulating the pointers of each node and at the end, the original head should be pointing towards NULL and the 
// original last node should be ‘head’ of the reversed Linked List. 

//  - In this type of scenario we first take a dummy node that will be assigned to NULL. 
//  - Then we take a next pointer which will be initialized to head->next and in future iterations, next will again be set 
//  to head->next
//  - Now coming to changes on head node, as we have set dummy node as NULL and next to head->next, we can now update the 
//  next pointer of the head to dummy node.
//  - Before moving to next iteration dummy is set to head and then head is set to next node.
//  - Now coming to next iteration : We’ll follow a similar process to set next as head->next and updating head->next = dummy, 
//  dummy set to head and head set to next
//  - These iterations will keep going while the head of original Linked List is not NULL, i.e. we’ll reach end of the 
//  original Linked List and the Linked List has been reversed.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while(head!=NULL){
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head=next;
        }
        return newHead;
    }
};