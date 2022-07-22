struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    Node *get(int bit)
    {
        return (links[bit]);
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int nums)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (nums >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int num)
    {
        Node *node = root;
        int maxsum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            //   Not Possible       (num & (1<<i));
            if (node->containsKey(1 - bit))
            {
                maxsum = maxsum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxsum;
    }
};
int maximumXor(vector<int> arr)
{
    // Write your code here.
    Trie trie;
    for (int i = 0; i < arr.size(); i++)
    {
        trie.insert(arr[i]);
    }
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res = max(res, trie.getMaxXor(arr[i]));
    }
    return res;
}