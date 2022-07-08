string serializeTree(TreeNode<int> *root)
{
    if (!root)
        return "";
    string s = "";
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();
        if (cur == NULL)
            s.append("#,");
        else
        {
            s.append(to_string(cur->data) + ',');
        }
        if (cur != NULL)
        {
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return s;
}

TreeNode<int> *deserializeTree(string &serialized)
{
    if (serialized.size() == 0)
        return NULL;

    stringstream s(serialized);
    string str;
    getline(s, str, ',');
    TreeNode<int> *root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            cur->left = NULL;
        }
        else
        {
            TreeNode<int> *leftN = new TreeNode<int>(stoi(str));
            cur->left = leftN;
            q.push(leftN);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            cur->right = NULL;
        }
        else
        {
            TreeNode<int> *rightN = new TreeNode<int>(stoi(str));
            cur->right = rightN;
            q.push(rightN);
        }
    }
    return root;
}