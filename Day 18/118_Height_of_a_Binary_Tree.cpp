// Recursive Approach - TC: O(n)  SC: O(h) - h is height of tree
// ---------------------------------------------------------------
// We start to travel recursively and do our work in Post Order.
// Reason behind using Post Order comes from our intuition , that if we know the result of  left and right child then we can
// calculate the result using that.
// This is exactly an indication of PostOrder, because in PostOrder we already calculated results for left and right children
// than we do it for current node.
// So for every node post order, we do Max( left result , right result ) + 1 and return it to the previous call.
// Base Case is when root == null so we need to return 0;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == 0)
            return 0;
        return 1 + max(maxDepth(root->right), maxDepth(root->left));
    }
};