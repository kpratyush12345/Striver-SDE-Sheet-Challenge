int lcs(string s, string t)
{
    vector<int> prev(t.size() + 1, 0), cur(t.size() + 1, 0);
    for (int i = 1; i < s.size() + 1; i++)
    {
        for (int j = 1; j < t.size() + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[t.size()];
}