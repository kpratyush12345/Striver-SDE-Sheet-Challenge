#define lli long long int

int count;
lli solve(TreeNode<int> *root, lli &ans)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        count++;
    lli left = solve(root->left, ans);
    lli right = solve(root->right, ans);

    lli temp = max(left, right) + root->val;

    lli mx = max(temp, left + right + root->val);
    ans = max(ans, mx);

    return temp;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return -1;
    count = 0;
    lli ans = 0;
    solve(root, ans);

    if (count == 1)
        return -1;
    return ans;
}