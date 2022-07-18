int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    // Write your code here
    int omax = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                maxi = max(maxi, dp[j]);
            }
        }
        if (maxi == 0)
            dp[i] = arr[i];
        else
            dp[i] = maxi + arr[i];

        if (dp[i] > omax)
            omax = dp[i];
    }
    return omax;
}