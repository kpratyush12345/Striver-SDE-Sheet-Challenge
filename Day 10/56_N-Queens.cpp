// Backtracking Approach - TC: O(N! * N)  SC: O(N^2)
// --------------------------------------------------
// Using the concept of Backtracking, we will place Queen at different positions of the chessboard and find the right
// arrangement where all the n queens can be placed on the n*n grid.

// 1st position: This is the position where we can see no possible arrangement is found where all queens can be placed since,
// at the 3rd column, the Queen will be killed at all possible positions of row.

// 2nd position: One of the correct possible arrangements is found. So we will store it as our answer.

// 3rd position: One of the correct possible arrangements is found. So we will store it as our answer.

// 4th position: This is the position where we can see no possible arrangement is found where all queens can be placed since,
// at the 4th column, the Queen will be killed at all possible positions of row.

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        // check upper element
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

// Optimised Approach - TC : O(N! * N)  SC: O(N)
// ----------------------------------------------
// This is the optimization of the issafe function. In the previous issafe function, we need o(N) for a row, o(N) for the
// column, and o(N) for diagonal. Here, we will use hashing to maintain a list to check whether that position can be the
// right one or not.

class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};