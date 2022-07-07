int findCeil(BinaryTreeNode<int> *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        if (root->data > key)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}