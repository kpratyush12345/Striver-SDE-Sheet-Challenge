#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int x = vec[i][0];
        int y = vec[i][1];
        int z = vec[i][2];
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    unordered_map<int, bool> vis;
    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> s;
    s.insert({0, source});
    dist[source] = 0;
    while (s.size() > 0)
    {
        auto top = *(s.begin());
        int d = top.first;
        int node = top.second;
        s.erase(s.begin());
        for (auto it : adj[node])
        {
            int child = it.first;
            int wt = it.second;
            if (dist[child] > d + wt)
            {
                dist[child] = d + wt;
                s.insert({dist[child], child});
            }
        }
    }
    return dist;
}