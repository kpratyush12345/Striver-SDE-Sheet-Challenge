// Optimised Approach - TC: O(n)  SC: O(n)
// ----------------------------------------
// Take a queue data structure and push the root node to the queue.
// Set a while loop which will run till our queue is non-empty.
// In every iteration, pop out from the front of the queue and assign it to a variable (say temp).
// If temp has a left child, push it to the queue.
// If temp has a right child, push it to the queue.
// At last push the value of the temp node to our “ans” data structure.

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};