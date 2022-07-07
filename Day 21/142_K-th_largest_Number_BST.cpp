int KthLargestNumber(TreeNode<int> *root, int k)
{
    stack<TreeNode<int> *> st;
    int cnt = 0;
    while (true)
    {
        if (root)
        {
            st.push(root);
            root = root->right;
        }
        else
        {
            if (st.empty())
                break;
            root = st.top();
            st.pop();
            cnt++;
            if (cnt == k)
                return root->data;
            root = root->left;
        }
    }
    return -1;
}