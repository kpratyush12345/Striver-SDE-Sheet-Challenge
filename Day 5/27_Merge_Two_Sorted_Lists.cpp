// Recursive Approach - TC: O(n+m)  SC: O(n+m) - m,n length of l1 and l2
// ---------------------------------------------------------------------
// We take a new result node and then push the value which is lesser and then do a recursive call for the next element.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = NULL;

        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;

        if (list1->val <= list2->val){
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else{
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }
        return result;
    }
};


// Optimised Approach - TC: O(n+m)  SC: O(1) - m,n length of l1 and l2
// ---------------------------------------------------------------------
// Step 1: Create two pointers, say l1 and l2. Compare the first node of both lists and find the small among the 
// two. Assign pointer l1 to the smaller value node.

// Step 2: Create a pointer, say res, to l1. An iteration is basically iterating through both lists till the value 
// pointed by l1 is less than or equal to the value pointed by l2.

// Step 3: Start iteration. Create a variable, say, temp. It will keep track of the last node sorted list in an 
// iteration. 

// Step 4: Once an iteration is complete, link node pointed by temp to node pointed by l2. Swap l1 and l2.

// Step 5: If any one of the pointers among l1 and l2 is NULL, then move the node pointed by temp to the next higher 
// value node.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val > l2->val) std::swap(l1,l2);
        ListNode * res =l1;
        while(l1!=NULL && l2 != NULL){
            ListNode * tmp = NULL;
            while(l1!=NULL && l1->val <= l2->val){
                tmp=l1;
                l1=l1->next;
            }
            tmp->next = l2;
            std::swap(l1,l2);
        }
        return res;
    }
};