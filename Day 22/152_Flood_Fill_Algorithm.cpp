void dfs(vector<vector<int>> &image, int x, int y, int color, int newColor, int dx[], int dy[])
{
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size())
        return;
    if (image[x][y] != color)
        return;
    image[x][y] = newColor;
    for (int i = 0; i < 4; i++)
    {
        dfs(image, x + dx[i], y + dy[i], color, newColor, dx, dy);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    if (image[x][y] == newColor)
        return image;
    int color = image[x][y];
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    dfs(image, x, y, color, newColor, dx, dy);
    return image;
}