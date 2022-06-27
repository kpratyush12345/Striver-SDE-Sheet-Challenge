// Approach 1
// ------------
// Finding the minimum length first and then iterate over that length and find if the current is equal to strs[j][i] and if
// not then return the resukt string or else push the current to the string.

class Solution
{
public:
    int findMinLength(vector<string> &strs, int n)
    {
        int min = strs[0].length();
        for (int i = 1; i < n; i++)
        {
            if (strs[i].length() < min)
                min = strs[i].length();
        }
        return min;
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        int minlen = findMinLength(strs, n);
        string result;
        char current;

        for (int i = 0; i < minlen; i++)
        {
            current = strs[0][i];

            for (int j = 1; j < n; j++)
            {
                if (strs[j][i] != current)
                    return result;
            }
            result.push_back(current);
        }
        return result;
    }
};

// Approach 2
// ------------
// We will find the common string using pattern matching.

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        if (strs.size() == 0)
            return res;
        if (strs.size() == 1)
            return strs[0];
        int j = 0;
        bool flag = false;
        while (true)
        {
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i - 1][j] != strs[i][j])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            if (j >= strs[0].size())
                break;
            j++;
        }

        for (int i = 0; i < j; i++)
            res += strs[0][i];
        return res;
    }
};