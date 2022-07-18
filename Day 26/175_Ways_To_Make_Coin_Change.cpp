long t[11][2001];
long solve(int i, int value, int *arr, int &n)
{
    if (i >= n)
        return 0;
    if (value < 0)
        return 0;

    if (value == 0)
        return 1;

    if (t[i][value] != -1)
        return t[i][value];

    long notTake = solve(i + 1, value, arr, n);
    long Take = solve(i, value - arr[i], arr, n);

    return t[i][value] = (notTake + Take);
}
long countWaysToMakeChange(int *arr, int n, int value)
{
    // Write your code here
    memset(t, -1, sizeof(t));
    return solve(0, value, arr, n);
}