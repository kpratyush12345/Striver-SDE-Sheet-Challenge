int dp[101][10001];
int func(int e, int f)
{
    if (f == 1 || f == 0)
    {
        return f;
    }

    if (e == 1)
    {
        // if only one eggs is left , then in worst u have to check every floor
        return f;
    }

    if (dp[e][f] != -1)
    {
        return dp[e][f];
    }

    int ans = INT_MAX; // minimum no of trials needed (till having e eggs , f floors)
    // finding the critical floor

    int l = 1;
    int h = f;

    while (l <= h)
    {
        int mid = (l + (h - l) / 2);

        int go_below = func(e - 1, mid - 1); // egg break at mid  , floor left is mid-1
        int go_above = func(e, f - mid);     // egg not break , no of floor left is f-mid

        // as we dont know egg will break or not

        // what we will do is we take the max no of trials from broken or not breoken

        int temp = 1 + max(go_above, go_below);

        if (go_above > go_below)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }

        ans = min(ans, temp);
    }

    return dp[e][f] = ans;
}

int cutLogs(int k, int n)
{
    memset(dp, -1, sizeof(dp));
    return func(k, n);
}