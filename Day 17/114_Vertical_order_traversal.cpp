// Recursive Approach
// -------------------

class Solution
{
    map<int, map<int, multiset<int>>> mymap;
    void solve(TreeNode *curr, int col, int row)
    {
        if (!curr)
            return;

        mymap[col][row].insert(curr->val);
        solve(curr->left, col - 1, row + 1);
        solve(curr->right, col + 1, row + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        solve(root, 0, 0);

        vector<vector<int>> ans;
        for (auto m1 : mymap)
        {
            vector<int> v;
            for (auto m2 : m1.second)
            {
                for (auto m3 : m2.second)
                    v.push_back(m3);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// Iterative Approach
// -------------------

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        map<int, vector<int>> mp;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int sz = q.size();
            multiset<pair<int, int>> s;

            for (int i = 0; i < sz; i++)
            {
                pair<TreeNode *, int> temp = q.front();
                q.pop();
                s.insert({temp.second, temp.first->val});
                if (temp.first->left != NULL)
                    q.push({temp.first->left, temp.second - 1});
                if (temp.first->right != NULL)
                    q.push({temp.first->right, temp.second + 1});
            }

            for (auto it : s)
            {
                mp[it.first].push_back(it.second);
            }
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};