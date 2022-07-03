#include <bits/stdc++.h>
TreeNode<int> *makeBT(vector<int> &inorder, vector<int> &preorder, int li, int hi, int lp, int hp, map<int, int> &mpp)
{
    if (lp < 0 || lp > hp)
        return NULL;
    //     cout<<postOrder[hp]<<endl;
    int rootData = preorder[lp];
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int index = mpp[rootData];
    int numLeft = lp + index - li;
    root->left = makeBT(inorder, preorder, li, index - 1, lp + 1, numLeft, mpp);
    root->right = makeBT(inorder, preorder, index + 1, hi, numLeft + 1, hp, mpp);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[inorder[i]] = i;
    }
    return makeBT(inorder, preorder, 0, n - 1, 0, n - 1, mpp);
}