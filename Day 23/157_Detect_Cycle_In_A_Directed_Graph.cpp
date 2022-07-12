// Using DFS
// ----------
bool detect_cycle(int src, vector<int> adj[], vector<int> &visit)
{
    visit[src] = 2;
    for (auto it : adj[src])
    {
        if (visit[it] == 0)
        {
            if (detect_cycle(it, adj, visit))
                return true;
        }
        else if (visit[it] == 2)
            return true;
    }
    visit[src] = 1;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<int> adj[n + 1];

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> visit(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        if (visit[i] == 0)
        {
            if (detect_cycle(i, adj, visit))
            {
                return 1;
            }
        }
    }
    return 0;
}

// Using BFS
// -----------

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    vector<int> indegree(n);

    for (auto i : adj)
    {
        for (auto j : i.second)
            indegree[j]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    if (count == n)
    {
        return false;
    }
    else
    {
        return true;
    }
}
