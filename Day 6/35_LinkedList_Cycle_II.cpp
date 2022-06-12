// Brute Force - TC: O(n)  SC: O(n)
// ---------------------------------
// 1. Iterate the given list.
// 2. For each node visited by head pointer, check if node is present in the hash table.
// 3. If yes, loop detected
// 4. If not, insert node in the hash table and move the head pointer ahead.
// 5. If head reaches null, then the given list does not have a cycle in it.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> st;
        while(head != NULL) {
            if(st.find(head) != st.end()) return head;
            st.insert(head);
            head = head->next;
        }
        return NULL;
    }
};


// Slow Fast Pointer Method - TC: O(n)  SC: O(1)
// ----------------------------------------------
// 1. Initially take two pointers, fast and slow. Fast pointer takes two steps ahead while slow pointer will take 
// single step ahead for each iteration.
// 2. We know that if a cycle exists, fast and slow pointers will collide.
// 3. If cycle does not exists, fast pointer will move to NULL
// 4. Else, when both slow and fast pointer collides, it detects a cycle exists.
// 5. Take another pointer, say entry. Point to the very first of the linked list.
// 6. Move the slow and the entry pointer ahead by single steps until they collide. 
// 7. Once they collide we get the starting node of the linked list.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL||head->next == NULL) return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *entry = head;

        while(fast->next != NULL&&fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};