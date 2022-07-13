// Using BFS
// ----------
bool check_bipartite(int src, vector<int> adj[], vector<int> &color)
{
    color[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges[0].size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (check_bipartite(i, adj, color) == false)
                return false;
        }
    }
    return true;
}

// Using DFS
// ----------
bool dfs(vector<int> adj[], vector<int> &color, int i)
{
    if (color[i] == -1)
    {
        color[i] = i;
    }

    for (auto x : adj[i])
    {
        if (color[x] == -1)
        {
            color[x] = 1 - color[i];
            if (!dfs(adj, color, x))
            {
                return false;
            }
        }
        else if (color[x] == color[i])
        {
            return false;
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> adj[n + 1];
    vector<int> color(n + 1, -1);
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[0].size(); j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(adj, color, i))
            {
                return false;
            }
        }
    }
    return true;
}