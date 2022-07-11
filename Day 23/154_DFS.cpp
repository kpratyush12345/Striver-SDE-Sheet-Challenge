void dfs(vector<int> adj[], int node, vector<int> &cmp, vector<int> &vis)
{

    cmp.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(adj, it, cmp, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    vector<int> adj[V];
    vector<int> vis(V, 0);
    vector<vector<int>> ans;
    for (int i = 0; i < E; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> cmp;
            dfs(adj, i, cmp, vis);
            ans.push_back(cmp);
        }
    }
    return ans;
}