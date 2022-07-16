
bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int findpar(int u, vector<int> &par)
{                                         // DISJOINT SET FIND
    if (u == par[u])                      // if reqd node present in set
        return u;                         // parent found, return parent
    return par[u] = findpar(par[u], par); // recur for parent to find the absolute parent
}

int union_(int u, int v, vector<int> &par)
{
    if (findpar(u, par) == findpar(v, par))                           // if both are part of same set
        return 0;                                                     // union not possible
    else if (!(u >= 0 && v >= 0 && u < par.size() && v < par.size())) // if anyone is out of bounds
        return 0;                                                     // union not possible
    par[u] = v;                                                       // save the better (more accurate) parent
}

int kruskalMST(int n, int m, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(), comp); // will iterate greedy
    vector<int> parent(n + 1);
    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;

    int cost = 0;
    // vector<pair<int,int>> mst; // incase need mst reqd too? keep storing here
    for (auto it : edges)
    {
        if (findpar(it[0], parent) != findpar(it[1], parent))
        {                                                                   // if nodes are from diff sets
            cost += it[2];                                                  // add the cost of the connection
            union_(findpar(it[0], parent), findpar(it[1], parent), parent); // join them
        }
    }
    return cost;
}