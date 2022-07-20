bool check(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}
int sol(string str, int n, int i, vector<int> &t)
{
    if (i == n)
        return 0;

    if (t[i] != -1)
        return t[i];
    int ans = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (check(str.substr(i, j - i + 1)))
        {
            int temp = 1 + sol(str, n, j + 1, t);
            ans = min(ans, temp);
        }
    }
    return t[i] = ans;
}
int palindromePartitioning(string str)
{
    vector<int> t(str.length(), -1);
    return sol(str, str.length(), 0, t) - 1;
}