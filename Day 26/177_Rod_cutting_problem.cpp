int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int j = 1; j <= n; j++)
        prev[j] = j * price[0];
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            prev[j] = max(prev[j], price[i - 1] + prev[j - i]);
        }
    }
    return prev[n];
}