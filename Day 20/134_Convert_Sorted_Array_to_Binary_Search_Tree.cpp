class Solution
{
public:
    TreeNode *constructBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *curr = new TreeNode(nums[mid]);
        curr->left = constructBST(nums, left, mid - 1);
        curr->right = constructBST(nums, mid + 1, right);
        return curr;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        return constructBST(nums, 0, nums.size() - 1);
    }
};