// Using DP - TC: O(n^2)  SC: O(n^2)
// ------------------------------------
// Use DP and mark already covered small sub-string is palindromic or not and use it for other longer sub-string.
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();

        // dp[i][j] will be false if substring s[i..j] is not palindrome, Else true
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        int start = 0, lenMax = 1;

        // check for sub-string of length 2.
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                lenMax = 2;
            }
        }

        // Check for sub-string of length greater than 2.
        for (int k = 3; k <= n; k++) // k is length of substring
        {
            for (int i = 0; i < n - k + 1; i++) // Fix the starting index
            {
                int j = i + k - 1; // Get the ending index of substring from starting index i and length k

                // checking for sub-string from ith index to jth index if s[i+1] to s[j-1] is a palindrome
                if (dp[i + 1][j - 1] == true && s[i] == s[j])
                {
                    dp[i][j] = true;

                    if (k > lenMax)
                    {
                        lenMax = k;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, lenMax); // print sub-string from start to lenMax
    }
};

// Two Pointer Approach - TC : O(2n^2)  SC: O(1)
// ---------------------------------------------
// For odd length palindromic substring, we start from same index and check for near characters
// For even length palindromic substring, start from adjacent index and check for near characters.

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int lenMax = 0;
        string res;

        for (int i = 0; i < s.length(); i++)
        {
            string odd = pali_subs(s, i, i); // start from same index for odd length palindrome
            long_subs(odd, res, lenMax);
            string even = pali_subs(s, i, i + 1); // start from adjacent index for even length palindrome
            long_subs(even, res, lenMax);
        }
        return res;
    }

    string pali_subs(string &s, int L, int R)
    {
        int n = s.size();
        while (L >= 0 && R < n) // iterate until L and R cross the boundary
        {
            if (s[L] != s[R])
                break;
            L--;
            R++;
        }
        return s.substr(L + 1, R - 1 - L); // return palindromic substring
    }

    void long_subs(string &new_s, string &res, int &lenMax)
    {
        if (new_s.size() > lenMax) // if
        {
            res = new_s;
            lenMax = new_s.size();
        }
    }
};
