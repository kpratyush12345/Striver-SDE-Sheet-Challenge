// Recursive Approach - TC: O(n)  SC: O(n)
// ----------------------------------------
//  In preorder traversal, the tree is traversed in this way: root, left, right.

// The algorithm approach can be stated as:

//  - We first visit the root node and before visiting its children we print its value.
//  - After this, we recursively visit its left child.
//  - Then we recursively visit the right child.
//  - If we encounter a node pointing to NULL, we simply return to its parent.

void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

// Iterative Approach - TC: O(n)  SC: O(n)
// ---------------------------------------
// We first take an explicit stack data structure and push the root node to it.(if the root node is not NULL).
// Then we use a while loop to iterate over the stack till the stack remains non-empty.
// In every iteration we first pop the stack’s top and print it.
// Then we first push the right child of this popped node and then push the left child, if they are not NULL. We do so because
// stack is a last-in-first-out(LIFO) data structure. We need to access the left child first, so we need to push it at the last.
// The execution continues and will stop when the stack becomes empty. In this process, we will get the preorder traversal of
// the tree.

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;
    if (root == NULL)
        return preorder;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        root = s.top();
        s.pop();
        preorder.push_back(root->data);
        if (root->right != NULL)
            s.push(root->right);
        if (root->left != NULL)
            s.push(root->left);
    }
    return preorder;
}