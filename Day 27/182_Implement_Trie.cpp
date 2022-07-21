class Trie
{
    vector<int> chr;
    vector<bool> isPresent;
    vector<Trie *> next;

public:
    /** Initialize your data structure here. */
    Trie() : chr(26, 0), isPresent(26, false), next(26, 0)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string &word, int pos = 0)
    {
        if (pos == word.length())
        {
            isPresent[word[pos - 1] - 'a'] = true;
            return;
        }
        if (chr[word[pos] - 'a'] == 1)
        {
            next[word[pos] - 'a']->insert(word, pos + 1);
            return;
        }
        chr[word[pos] - 'a'] = 1;
        next[word[pos] - 'a'] = new Trie;
        next[word[pos] - 'a']->insert(word, pos + 1);
        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string &word, int pos = 0)
    {
        if (word.length() == pos && isPresent[word[pos - 1] - 'a'])
            return true;
        else if (word.length() == pos)
            return false;
        else if (next[word[pos] - 'a'] == 0)
            return false;
        else if (chr[word[pos] - 'a'] == 0)
            return false;
        return next[word[pos] - 'a']->search(word, pos + 1);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string &prefix, int pos = 0)
    {
        if (prefix.length() == pos)
            return true;
        else if (next[prefix[pos] - 'a'] == 0)
            return false;
        else if (chr[prefix[pos] - 'a'] == 0)
            return false;
        return next[prefix[pos] - 'a']->startsWith(prefix, pos + 1);
    }
};