// Using Map - TC: O(2*n)  SC: O(n)
// ----------------------------------
// So basically we are creating a map with Node*, Node* in which we first iterate, create and store all the nodes and lastly 
// again we iterate andstore the next random pointers in that map only. Return the maps head.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};


// Optimised Approach - TC: O(3*n)  SC: O(1)
// ------------------------------------------
// Steps are written in the code below and for better explaination : https://youtu.be/VNf6VynfpdM

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
        Node *front = head;

        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
        }

        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        // Third round: restore the original list, and extract the copy list.
        iter = head;
        Node *pseudoHead = new Node(0);
        Node *copy = pseudoHead;

        while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
        }
        return pseudoHead->next;
    }
};