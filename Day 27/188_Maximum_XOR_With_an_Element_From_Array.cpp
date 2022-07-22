struct node
{
    node *next[2] = {NULL};
};
class trie
{
    node *root;

public:
    trie()
    {
        root = new node;
    }

    void insert(int n)
    {
        node *head = root;
        for (int i = 31; i >= 0; i--)
        {
            if ((n >> i) & 1)
            {
                if (!head->next[1])
                    head->next[1] = new node;
                head = head->next[1];
            }
            else
            {
                if (!head->next[0])
                    head->next[0] = new node;
                head = head->next[0];
            }
        }
    }

    int maxor(int n)
    {
        node *head = root;
        int t = 0;
        for (int i = 31; i >= 0; i--)
        {
            if ((n >> i) & 1)
            {
                if (head->next[0])
                {
                    t = (t | (1 << i));
                    head = head->next[0];
                }
                else
                    head = head->next[1];
            }
            else
            {
                if (head->next[1])
                {
                    t = (t | (1 << i));
                    head = head->next[1];
                }
                else
                    head = head->next[0];
            }
        }
        // cout<<n<<" "<<t<<"\n";
        if (!t)
            return -1;
        return t;
    }
};
bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
vector<int> maxXorQueries(vector<int> &nums, vector<vector<int>> &q)
{
    // Write your coode here.
    for (int i = 0; i < q.size(); i++)
        q[i].push_back(i);
    sort(nums.begin(), nums.end());
    sort(q.begin(), q.end(), comp);
    int i = 0;
    trie *t = new trie();
    vector<int> ans(q.size(), -1);
    for (int k = 0; k < q.size(); k++)
    {
        int a = q[k][0];
        int b = q[k][1];
        int c = q[k][2];
        while (i < nums.size() and nums[i] <= b)
            t->insert(nums[i++]);
        if (i)
            ans[c] = t->maxor(a);
    }
    return ans;
}