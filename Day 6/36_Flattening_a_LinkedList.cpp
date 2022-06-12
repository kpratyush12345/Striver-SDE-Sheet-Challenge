// Optimised Approach - TC: O(n)  SC: O(1)
// -----------------------------------------
// Since each list, followed by the bottom pointer, are in sorted order. Our main aim is to make a single list in 
// sorted order of all nodes. So, we can think of a merge algorithm of merge sort.

// The process to flatten the given linked list is as follows:-

//  - We will recurse until the head pointer moves null. The main motive is to merge each list from the last.
//  - Merge each list chosen using the merge algorithm. The steps are
//  - Create a dummy node. Point two pointers, i.e, temp and res on dummy node. res is to keep track of dummy node and 
//  temp pointer is to move ahead as we build the flatten list.
//  - We iterate through the two chosen. Move head from any of the chosen list ahead whose current pointed node is 
//  smaller. 
//  - Return the new flattened list found.

Node* mergeTwoLists(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b;
    temp->next = NULL; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root){
   
    if (root == NULL || root->next == NULL) 
        return root; 
  
    // recur for list on right 
    root->next = flatten(root->next); 
  
    // now merge 
    root = mergeTwoLists(root, root->next); 
  
    // return the root 
    // it will be in turn merged with its left 
    return root; 
}