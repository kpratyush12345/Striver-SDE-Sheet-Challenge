// Brute Force - TC: O(nlogn)  SC: O(1)
// ---------------------------------------
// Simply sort both s and t and check if both are equal if they are then return true else false.

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else
            return false;
    }
};

// Hash Table - TC: O(n)  SC: O(n)
// --------------------------------
// This idea uses a hash table to record the times of appearances of each letter in the two strings s and t. For each letter in
// s, it increases the counter by 1 while for each letter in t, it decreases the counter by 1. Finally, all the counters will be
// 0 if they two are anagrams of each other.

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++)
        {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second)
                return false;
        return true;
    }
};

// Using Count Array - TC: O(n)  SC: O(n)
// ------------------------------------------
// Since the problem statement says that "the string contains only lowercase alphabets", we can simply use an array to simulate
// the unordered_map and speed up the code.

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i])
                return false;
        return true;
    }
};