// Brute Force - TC: O(m) + O(m)  SC: O(1) - m is length of head
// ---------------------------------------------------------------
// We can traverse through the Linked List while maintaining a count of nodes, let’s say in variable count , and 
// then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode();
        temp=head;
        int size=0;
        while(head!=0){
            size++;
            head=head->next;
        }
        if(size==1){
            temp=NULL;
            return temp;
        }
        head=temp;
        int s=size-n;
        if(s==0){
            temp=head->next;
            return temp;
        }
        int c=1;
        while(c!=s){
            head=head->next;
            c++;
        }
        head->next=head->next->next;
        return temp;
    }
};


// Brute Force - TC: O(m)  SC: O(1) - m is length of head
// ----------------------------------------------------------
// 1. Take two dummy nodes, who’s next will be pointing to the head.
// 2. Take another node to store the head, initially it,s a dummy node(start), and the next of the node will be 
// pointing to the head.The reason why we are using this extra dummy node, is because there is an edge case. If the 
// node is equal to the length of the linkedlist, then this slow’s will point to slow’s next→ next. And we can say 
// our dummy start node will be broken, and will be connected to the slow’s next→ next.
// 3. Start traversing until the fast pointer reaches the nth node.

// 4. Now start traversing by one step both of the pointers until the fast pointers reach the end.    

// 5. When the traversal is done, just do the deleting part. Make  slow pointer’s next to the next of next of the 
// slow pointer to ignore/disconnect the given node.

// 6. Last, return the next of start.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || n==0) return head;
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;  

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};