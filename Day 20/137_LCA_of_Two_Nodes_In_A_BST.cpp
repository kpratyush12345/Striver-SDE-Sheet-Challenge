TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    // Write your code here
    while (root != NULL)
    {
        if (root->data > P->data && root->data > Q->data)
            root = root->left;
        else if (root->data < P->data && root->data < Q->data)
            root = root->right;
        else
            return root;
    }
}
