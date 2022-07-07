int floorInBST(TreeNode<int> *root, int x)
{
    int ceil = -1;
    while (root)
    {
        if (root->val == x)
        {
            ceil = root->val;
            return ceil;
        }

        if (x < root->val)
        {
            root = root->left;
        }
        else
        {
            ceil = root->val;
            root = root->right;
        }
    }
    return ceil;
}