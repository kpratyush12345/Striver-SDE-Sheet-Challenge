// Brute Force - TC: O(n) + O(n/2)  SC: O(1)
// -------------------------------------------
// We can traverse through the Linked List while maintaining a count of nodes let’s say in variable n , and then traversing 
// for 2nd time for n/2 nodes to get to the middle of the list.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        	temp = temp->next;
    	}
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        	temp = temp->next;
    	}
    	return temp;
    }
};


// Tortoise Hare Approach - TC: O(n)  SC: O(1)
// ---------------------------------------------
// 1. Create two pointers slow and fast and initialize them to a head pointer.
// 2. Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
// 3. When the above condition is met, we can see that the slow ptr is pointing towards the middle of Linked List and hence 
// we can return the slow pointer.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};