// Hashing - TC: O(n)  SC: O(n) - n length of head
// -------------------------------------------------
// 1. Use a hash table for storing nodes. 
// 2. Start iterating through the lists.
// 3. If the current node is present in the hash table already, this indicates the cycle is present in the linked 
// list and returns true.
// 4. Else move insert the node in the hash table and move ahead.
// 5. If we reach the end of the list, which is NULL, then we can say that the given list does not have a cycle in 
// it and hence we return false.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> hashTable;
        while(head != NULL) {
            if(hashTable.find(head) != hashTable.end()) return true;
            hashTable.insert(head);
            head = head->next;
        }
        return false;
    }
};

// Slow and Fast Pointer - TC: O(n)  SC: O(1) - n length of head
// --------------------------------------------------------------
// 1. We will take two pointers, namely fast and slow. Fast pointer takes 2 steps ahead and slow pointer takes 2 
// points ahead.
// 2. Iterate through the list until the fast pointer is equal to NULL. This is because NULL indicates that there 
// is no cycle present in the given list.
// 3. Cycle can be detected when fast and slow pointers collide.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};