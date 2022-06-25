// Using Stack - TC: O(N)  SC: O(N)
// --------------------------------------
int findCelebrity(int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);

    while (!s.empty() and s.size() > 1)
    {
        int val1 = s.top();
        s.pop();
        int val2 = s.top();
        s.pop();
        knows(val1, val2) == true ? s.push(val2) : knows(val2, val1) == true ? s.push(val1)
                                                                             : void(0);
    }

    if (!s.empty())
    {
        int val = s.top();
        int count = 0;
        for (int i = 0; i < n; i++) // check for celebrity row  it should be 0
        {
            if (knows(val, i) == true)
                return -1;
        }

        for (int i = 0; i < n; i++) // check for celebrity col
        {
            if (knows(i, val) == true)
                count++;
        }
        if (count >= 1)
            return val;
    }
    return -1;
}

// Optimised Approach - TC: O(n)  SC: O(1)
// ----------------------------------------
int findCelebrity(int n)
{
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (knows(c, i) == 1)
        {
            c = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != c and (knows(c, i) == 1 or knows(i, c) == 0))
            return -1;
    }
    return c;
}