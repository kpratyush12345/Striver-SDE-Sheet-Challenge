// PostOrder Approach - TC: O(1)  SC: O(h) - h is height of the tree
// ------------------------------------------------------------------
// Start traversing the tree recursively and do work in Post Order.
// In the Post Order of every node , calculate diameter and height of the current node.
// If current diameter is maximum then update the variable used to store the maximum diameter.
// Return height of current node to the previous recursive call.

class Solution
{
public:
    int height(TreeNode *node, int &diameter)
    {
        if (!node)
            return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};