// Recursive Approach - TC: O(n)  SC: O(n)
// ------------------------------------------
// We first recursively visit the left child and go on left till we find a node pointing to NULL.
// Then we return to its parent.
// Then we recursively visit the right child.
// After we have returned from the right child as well, only then will we print the  current node value.

void postorder(vector<int> &ans, TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(ans, root->left);
    postorder(ans, root->right);
    ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(ans, root);
    return ans;
}