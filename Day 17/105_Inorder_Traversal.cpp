// Recursive Approach - TC: O(n)  SC: O(n)
// ----------------------------------------
// In inorder traversal, the tree is traversed in this way: left, root, right.

// The algorithm approach can be stated as:

//  - We first recursively visit the left child and go on till we find a leaf node.
//  - Then we print that node value.
//  - Then we recursively visit the right child.
//  - If we encounter a node pointing to NULL, we simply return to its parent.

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

// Iterative Approach - TC: O(n)  SC: O(n)
// ----------------------------------------
// We first take an explicit stack data structure and set an infinite loop.
// In every iteration we check whether our current node is pointing to NULL or not.
// If it is not pointing to null, we simply push the current value to the stack and move the current node to its left child.
// If it is pointing to NULL, we first check whether the stack is empty or not. If the stack is empty, it means that we have
// traversed the tree and we break out of the loop.
// If the stack is not empty, we pop the top value of the stack, print it and move the current node to its right child.
// Stack is a Last-In-First-Out (LIFO) data structure, therefore when we encounter a node, we simply push it to the stack and
// try to find nodes on its left. When the current node points to NULL, it means that there is nothing left to traverse and we
// should move to the parent. This parent is always placed at the top of the stack. If the stack is empty, then we had already
// traversed the whole tree and should stop the execution.

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    stack<TreeNode *> s;
    while (true)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if (s.empty())
                break;
            root = s.top();
            inorder.push_back(root->data);
            s.pop();
            root = root->right;
        }
    }
    return inorder;
}