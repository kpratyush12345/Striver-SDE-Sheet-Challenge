// Brute Force - TC: O(n*k)  SC: O(1) - n is length of list
// ---------------------------------------------------------
// We have to move the last element to first for each k. For each k, find the last element from the list. Move it 
// to the first.
// We can see that for every k which is multiple of the length of the list, we get back the original list. Try to 
// operate brute force on any linked list for k as multiple of the length of the list.
// This gives us a hint that for k greater than the length of the list, we have to rotate the list for k%length of 
// the list. This reduces our time complexity.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
        
        ListNode* temp = head;
        int length = 1;
        while(temp->next != NULL) {
            ++length;
            temp = temp->next;
        }
        k = k % length;
        for(int i=0;i<k;i++) {
            ListNode* temp = head;
            while(temp->next->next != NULL) temp = temp->next;
            ListNode* end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }
        return head;
    }
};


// Optimised Approach - TC: O(n) + O(n - n*k)  SC: O(1) - n is length of list
// ---------------------------------------------------------------------------
// 1. Calculate length of the list
// 2. Connect the last node to the first node, converting it to a circular linked list.
// 3. Iterate to cut the link of the last node and start a node of k%length of list rotated list.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||head->next == NULL||k == 0) return head;
        
        ListNode* temp = head;
        int length = 1;
        while(temp->next != NULL) {
            ++length;
            temp = temp->next;
        }
        
        temp->next = head;
        k = k%length; 
        int end = length-k;
        while(end--) temp = temp->next;
        
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};