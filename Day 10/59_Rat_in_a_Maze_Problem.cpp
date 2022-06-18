// Recursive Approach - TC: O(4^(m*n))  SC: O(m*n)
// ------------------------------------------------
// Start at the source(0,0) with an empty string and try every possible path i.e upwards(U), downwards(D), leftwards(L) and
// rightwards(R).
// As the answer should be in lexicographical order so it’s better to try the directions in lexicographical order i.e (D,L,R,U)
// Declare a 2D-array named visited because the question states that a single cell should be included only once in the path,so
// it’s important to keep track of the visited cells in a particular path.
// If a cell is in path, mark it in the visited array.
// Also keep a check of the “out of bound” conditions while going in a particular direction in the matrix.
// Whenever you reach the destination(n,n) it’s very important to get back as shown in the recursion tree.
// While getting back, keep on unmarking the visited array for the respective direction.Also check whether there is a different
// path possible while getting back and if yes, then mark that cell in the visited array.

class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
               vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }

        // downward
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }

        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }

        // right
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }

        // upward
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis);
        return ans;
    }
};

// But, writing an individual code for every direction is a lengthy process therefore we truncate the 4 “if statements” into a single for loop using the following approach.

class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
               vector<vector<int>> &vis, int di[], int dj[])
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++)
        {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1)
            {
                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis, di, dj);
        return ans;
    }
};
