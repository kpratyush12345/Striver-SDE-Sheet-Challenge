int maximumProduct(vector<int> &arr, int n)
{

    int ans = INT_MIN;
    int maxx = 1;
    int minn = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            int temp = maxx;
            maxx = max(minn * arr[i], arr[i]);
            minn = min(temp * arr[i], arr[i]);
        }
        else if (arr[i] >= 0)
        {
            maxx = max(maxx * arr[i], arr[i]);
            minn = min(minn * arr[i], arr[i]);
        }

        ans = max(ans, maxx);
    }
    return ans;
}