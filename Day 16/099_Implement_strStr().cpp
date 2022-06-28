// Brute Force
// ------------
// Traverse all the possible starting points of haystack (from 0 to haystack.length() - needle.length()) and see if the
// following characters in haystack match those of needle.

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[j])
            {
                bool flag = true;
                int k = i;
                while (j < needle.length())
                {
                    if (haystack[k] != needle[j])
                    {
                        j = 0;
                        flag = false;
                        break;
                    }
                    k++;
                    j++;
                }
                if (flag)
                    return i;
            }
        }
        return -1;
    }
};

// Using KMP Algorithm
// ----------------------

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (!n)
        {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;)
        {
            if (haystack[i] == needle[j])
            {
                i++, j++;
            }
            if (j == n)
            {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j])
            {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }

private:
    vector<int> kmpProcess(string needle)
    {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;)
        {
            if (needle[i] == needle[len])
            {
                lps[i++] = ++len;
            }
            else if (len)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};