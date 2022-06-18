// Backtracking Approach
// ------------------------

void words(string &s, int start, vector<string> &dictionary, vector<string> &ans, string &curr)
{
    // We've reached end of string
    if (start >= s.size())
    {
        ans.push_back(curr);
        return;
    }
    for (int i = start; i < s.size(); ++i)
    {
        string tmp = s.substr(start, i - start + 1);
        // Check if this word is present in dictionary
        bool isPresent = false;
        for (string st : dictionary)
        {
            if (st.compare(tmp) == 0)
            {
                isPresent = true;
                break;
            }
        }
        // If this word is present in dictionary
        // then try the remaining string
        if (isPresent)
        {
            string x = curr;
            // Push this to current ans
            curr += tmp + " ";
            words(s, i + 1, dictionary, ans, curr);
            // Backtracking
            curr = x;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string curr;
    words(s, 0, dictionary, ans, curr);
    return ans;
}