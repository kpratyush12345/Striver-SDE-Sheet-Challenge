// BFS Approach - TC: O(n)  SC: O(n)
// ----------------------------------
// We take a queue and push the root node along with index 0.
// We traverse the tree using a level order traversal.
// In the level order traversal we set another loop to run for the size of the queue, so that we visit the same level nodes
// inside it.
// Before a level starts, we use a variable(say curMin) to store the index of the first node.
// We assign an index to every node, and to its children as described above.
// When the inner loop is at the first node of a level, we store its index in another variable(sayleftMost)
// When the inner loop is at the last node of a level, we store its index in another variable(say rightMost)
// After a level  in the outer loop, we calculate the width of the level as (rightMost – leftMost +1).
// We return the maximum width as the answer.

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int curMin = q.front().second;
            int leftMost, rightMost;
            for (int i = 0; i < size; i++)
            {
                int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
                TreeNode *temp = q.front().first;
                q.pop();
                if (i == 0)
                    leftMost = cur_id;
                if (i == size - 1)
                    rightMost = cur_id;
                if (temp->left)
                    q.push({temp->left, cur_id * 2 + 1});
                if (temp->right)
                    q.push({temp->right, cur_id * 2 + 2});
            }
            ans = max(ans, rightMost - leftMost + 1);
        }
        return ans;
    }
};

// Recursive Approach - TC: O(n)  SC: O(n)
// ------------------------------------------
// Same as Above

class Solution
{
public:
    long long ans;
    vector<long long> left;

    void dfs(TreeNode *root, int lvl, long long pos)
    {
        if (!root)
            return;
        if (left.size() == lvl)
        {
            left.push_back(pos);
        }

        ans = max(ans, pos - left[lvl] + 1);
        dfs(root->left, lvl + 1, pos * 2 - left[lvl]);
        dfs(root->right, lvl + 1, pos * 2 + 1 - left[lvl]);
    }

    int widthOfBinaryTree(TreeNode *root)
    {
        ans = 0;
        dfs(root, 0, 1);
        return ans;
    }
};