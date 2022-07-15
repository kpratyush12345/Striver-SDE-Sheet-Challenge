int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    for (auto it : edges)
    {
        dist[it[0]][it[1]] = it[2];
    }

    int i = 1;
    while (i <= n)
    {
        dist[i][i] = 0;
        i++;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist[src][dest];
}