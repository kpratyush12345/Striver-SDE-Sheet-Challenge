class BSTiterator
{
public:
    stack<TreeNode<int> *> order;
    BSTiterator(TreeNode<int> *root)
    {
        inorder(root);
    }

    void inorder(TreeNode<int> *root)
    {
        while (root != NULL)
        {
            order.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode<int> *topi = order.top();
        order.pop();
        inorder(topi->right);
        return topi->data;
    }

    bool hasNext()
    {
        return !order.empty();
    }
};