void count_islands(int i, int j, int n, int m, int **arr)
{
    if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == 1)
    {
        arr[i][j] = 0;

        count_islands(i, j + 1, n, m, arr);
        count_islands(i + 1, j, n, m, arr);
        count_islands(i, j - 1, n, m, arr);
        count_islands(i - 1, j, n, m, arr);
        count_islands(i - 1, j + 1, n, m, arr);
        count_islands(i + 1, j + 1, n, m, arr);
        count_islands(i - 1, j - 1, n, m, arr);
        count_islands(i + 1, j - 1, n, m, arr);
    }
}

int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
                count_islands(i, j, n, m, arr);
            }
        }
    }
    return count;
}