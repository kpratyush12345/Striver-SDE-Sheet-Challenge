// Recursion - TC: O(n)  SC: O(n)
// -------------------------------
// First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.
// Then we need a map data structure to store the lines and the nodes. This map will store the data in the form of sorted orders
// of keys(Lines).
// Here we will follow the level order traversal.
// Traverse through the nodes starting with root,0 and store them to the queue.
// Until the queue is not empty, store the node  and line no. in 2 separate variables .
// Then store the line and the node->val to the map, if there will be any node value present that corresponds to a line in the
// map , it will be replaced by the new node value and by this we will get the last node of each line.
// Store the node->left and node->right along with their line nos. to the queue.
// Then print the node->val from the map

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;
            mpp[line] = node->data;

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};