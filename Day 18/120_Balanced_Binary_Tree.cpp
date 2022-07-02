// PostOrder Approach - TC: O(n)  SC: (h)
// -----------------------------------------
// Start traversing the tree recursively and do work in Post Order.
// For each call, caculate the height of the root node, and return it to previous calls.
// Simultaneously, in the Post Order of every node , Check for condition of balance as information of left and right subtree
// height is available.
// If it is balanced , simply return height of current node and if not then return -1.
// Whenever the subtree result is -1 , simply keep on returning -1.

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = dfsHeight(root->left);

        if (leftHeight == -1)
            return -1;

        int rightHeight = dfsHeight(root->right);

        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};