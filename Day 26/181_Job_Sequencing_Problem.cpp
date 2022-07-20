int f(vector<vector<int>> &jobs, int i, int t, int n, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][t] != -1)
        return dp[i][t];
    int skip = f(jobs, i + 1, t, n, dp);
    int done = 0;
    if (jobs[i][0] - t > 0)
        done = jobs[i][1] + f(jobs, i + 1, t + 1, n, dp);
    return dp[i][t] = max(skip, done);
}
int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end());
    int n = jobs.size();
    vector<int> dp(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = n - 1; t >= 0; t--)
        {
            int skip = dp[t];
            int done = 0;
            if (jobs[i][0] - t > 0)
                done = jobs[i][1] + dp[t + 1];
            curr[t] = max(skip, done);
        }
        dp = curr;
    }
    return dp[0];
}