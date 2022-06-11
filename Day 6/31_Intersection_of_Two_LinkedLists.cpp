// Brute Force - TC: O(m*n)  SC: O(1) - m,n length of list1 and list2
// --------------------------------------------------------------------
// 1. Keep any one of the list to check its node present in the other list. Here, we are choosing the second list 
// for this task.
// 2. Iterate through the other list. Here, it is the first one. 
// 3. Check if the both nodes are the same. If yes, we got our first intersection node.
// 4. If not, continue iteration.
// 5. If we did not find an intersection node and completed the entire iteration of the second list, then there is 
// no intersection between the provided lists. Hence, return null.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB != NULL) {
            ListNode *temp = headA;
            while(temp != NULL) {
                if(temp == headB) return headB;
                temp = temp->next;
            }
            headB = headB->next;
        }
        return NULL;
    }
};


// Hashing - TC: O(m+n)  SC: O(m) - m,n length of list1 and list2
// --------------------------------------------------------------------
// Can we improve brute-force time complexity? In brute force, we are basically performing “searching”. We can 
// also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So 
// the process is as follows:-

//     - Iterate through list 1 and hash its node address. Why? (Hint: depends on common attribute we are searching)
//     - Iterate through list 2 and search the hashed value in the hash table. If found, return node.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> st;
        while(headA != NULL) {
           st.insert(headA);
           headA = headA->next;
        }
        while(headB != NULL) {
            if(st.find(headB) != st.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};


// Difference of length - TC: O(2*max(m,n))+O(abs(m-n))+O(min(m,n))  SC: O(1) - m,n length of list1 and list2
// ----------------------------------------------------------------------------------------------------------
// 1. Find length of both the lists.
// 2. Find the positive difference of these lengths.
// 3. Move the dummy pointer of the larger list by difference achieved. This makes our search length reduced to 
// the smaller list length.
// 4. Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.

class Solution {
public:
    int getDifference(ListNode *head1, ListNode *head2) {
        int len1 = 0, len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; 
                head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; 
                head2 = head2->next;
            }
        }
        return len1 - len2;
    }
    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int diff = getDifference(head1,head2);
        if(diff < 0) {
            while(diff != 0){
                head2 = head2->next;
                diff++;
            } 
        }     
        else{
            while(diff--) head1 = head1->next;
        } 
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return NULL;
    }
};


// Brute Force - TC: O(2*max(m,n))  SC: O(1) - m,n length of list1 and list2
// --------------------------------------------------------------------------
// 1. Take two dummy nodes for each list. Point each to the head of the lists.
// 2. Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue 
// iterating until they collide.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode *d1 = head1;
        ListNode *d2 = head2;

        while(d1 != d2) {
            d1 = d1 == NULL ? head2 : d1->next;
            d2 = d2 == NULL ? head1 : d2->next;
        }
        return d1;
    }
};