bool func(int sum, int i, vector<int> arr, int n, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (sum < 0)
        return false;
    if (i > n - 1)
        return false;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    if (func(sum - arr[i], i + 1, arr, n, dp) or func(sum, i + 1, arr, n, dp))
        return dp[i][sum] = true;
    return dp[i][sum] = false;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    //     return func(k,0,arr,n,dp);
    if (arr[n - 1] <= k)
        dp[n - 1][arr[n - 1]] = 1;
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int sum = k; sum >= 0; sum--)
        {
            if (sum >= arr[i])
            {
                if (dp[i + 1][sum - arr[i]])
                    dp[i][sum] = 1;
            }
            if (dp[i][sum] == 0)
                dp[i][sum] = dp[i + 1][sum];
        }
    }
    return dp[0][k];
}