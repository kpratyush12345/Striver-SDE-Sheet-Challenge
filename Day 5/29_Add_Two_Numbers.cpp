// Optimised Approach - TC: O(max(m,n))  SC: O(max(m,n)) - m,n length of l1 and l2
// --------------------------------------------------------------------------------
// 1. Create a dummy node which is the head of new linked list.
// 2. Create a node temp, initialise it with dummy.
// 3. Initialize carry to 0.
// 4. Loop through lists l1 and l2 until you reach both ends, and until carry is present.
//     - Set sum = l1.val + l2.val + carry.
//     - Update carry=sum/10.
//     - Create a new node with the digit value of (sum%10) and set it to temp node’s next, then advance temp node 
//     to next.
//     - Advance both l1 and l2.
// 4. Return dummy’s next node.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};