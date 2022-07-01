// Recursive Approach - TC: O(n)  SC: O(n)
// -----------------------------------------
// We pass the function with our root node, the path list and node V.
// For the base case, if root is pointing to NULL, we return false as clearly node V can’t be found.
// Now we first push the node to our path list.
// Then we check whether the current node is the target node or not, if it is then no further execution is needed and we return
// to the parent function.
// If not, then we recursively call its left and right child to find the target node V. If any one of them returns true, it
// means we have found node V at lower levels and return true from the current function.
// If the value is not found at the current node and neither in any of the recursive calls, it means that the value is not
// present in the current sub-tree, therefore we pop out the current node from the path list and return false.

bool getPath(TreeNode *root, vector<int> &arr, int x)
{
    if (!root)
        return false;

    arr.push_back(root->val);

    if (root->val == x)
        return true;

    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;

    arr.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> ans;
    getPath(A, ans, B);
    return ans;
}