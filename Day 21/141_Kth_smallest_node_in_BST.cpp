void inorder(TreeNode<int> *root, vector<int> &vec)
{
    if (!root)
        return;

    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int> vec;
    inorder(root, vec);

    for (int i = 0; i < vec.size(); i++)
    {
        if (i + 1 == k)
        {
            return vec[i];
        }
    }
    return 0;
}