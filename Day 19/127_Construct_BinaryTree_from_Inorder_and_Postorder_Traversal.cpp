TreeNode<int> *makeBT(vector<int> &inOrder, vector<int> &postOrder, int li, int hi, int lp, int hp, map<int, int> &mpp)
{
    if (lp < 0 || lp > hp)
        return NULL;
    //     cout<<postOrder[hp]<<endl;
    int rootData = postOrder[hp];
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int index = mpp[rootData];
    int numLeft = lp + index - li;
    root->left = makeBT(inOrder, postOrder, li, index - 1, lp, numLeft - 1, mpp);
    root->right = makeBT(inOrder, postOrder, index + 1, hi, numLeft, hp - 1, mpp);
    return root;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    int n = inOrder.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[inOrder[i]] = i;
    }
    return makeBT(inOrder, postOrder, 0, n - 1, 0, n - 1, mpp);
}