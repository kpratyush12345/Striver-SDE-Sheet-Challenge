#include <bits/stdc++.h>
void bfs(vector<int> &ans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();

        // store frontnode in ans
        ans.push_back(frontnode);

        // adj node dal do
        for (auto i : adj[frontnode])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> vis;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < vertex; i++)
        adj[i].sort();
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            bfs(ans, adj, vis, i);
        }
    }

    return ans;
}