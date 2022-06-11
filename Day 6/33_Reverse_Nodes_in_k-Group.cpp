// Optimised Approach - TC: O((n*k)/k) = O(n)  SC: O(1) - n length of head
// ------------------------------------------------------------------------
// 1. Create a dummy node. Point next to this node to head of the linked list provided.
// 2. Iterate through the given linked list to get the length of the list.
// 3. Create three pointer pre,cur and nex to reverse each group. Why? If we observe output, we can see that we have to reverse each group, apart from modifying links of group.
// 4. Iterate through the linked list until the length of list to be processed is greater than and equal to given k.
// 5. For each iteration, point cur to pre->next and nex to nex->next.
// 6. Start nested iteration for length of k.
// 7. For each iteration, modify links as following steps:-
//     cur->next = nex->next
//     nex->next = pre->next
//     pre->next = nex
//     nex = cur->next
// 8. Move pre to cur and reduce length by k.

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || k == 1) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *cur = dummy, *nex, *pre = dummy;
        int count = 0;
        
        while(cur->next != NULL){
            cur = cur->next;
            count++;
        } 
        
        while(count >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i = 0;i < k - 1;i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }
        return dummy->next;
    }
};