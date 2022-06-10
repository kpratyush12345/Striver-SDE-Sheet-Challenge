// Optimised Approach - TC: O(1)  SC: O(1)
// ----------------------------------------
// We are given access to nodes that we have to delete from the linked list. So, whatever operation we want to do 
// in the linked list, we can operate in the right part of the linked list from the node to be deleted. 

// The approach is to copy the next node’s value in the deleted node. Then, link node to next of next node. This 
// does not delete that node but indirectly it removes that node from the linked list.

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        temp->next = NULL;
    }
};