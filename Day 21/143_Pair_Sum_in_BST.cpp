void inorder(BinaryTreeNode<int> *root, unordered_map<int, int> &mp)
{
    if (!root)
        return;

    inorder(root->left, mp);
    mp[root->data]++;
    inorder(root->right, mp);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_map<int, int> mp;
    inorder(root, mp);

    for (auto x : mp)
    {
        int num = k - x.first;
        mp[x.first]--;
        if (mp.find(num) != mp.end() && mp[num] >= 1)
        {
            return true;
        }
        mp[x.first]++;
    }
    return false;
}