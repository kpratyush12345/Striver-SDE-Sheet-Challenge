// Brute Force - TC: O(n)  SC: O(n) - n is length of head
// ---------------------------------------------------------
// We can store elements in an array. Then check if the given array is a palindrome.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }
        for(int i=0;i<arr.size()/2;i++) 
            if(arr[i] != arr[arr.size()-i-1]) return false;
        return true;
    }
};

// Slow Fast Pointer - TC: O(n/2)  SC: O(1) - n is length of head
// ---------------------------------------------------------------
// 1. Find the middle element of the linked list. 
// 2. Reverse linked list from next element of middle element.
// 3. Iterate through the new list until the middle element reaches the end of the list.
// 4. Use a dummy node to check if the same element exists in the linked list from the middle element.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* cur = slow;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        fast = head;
        while(prev!=NULL){
            if(fast->val != prev->val) return false;
            fast = fast->next;
            prev = prev->next;
        }
        return true;
    }
};