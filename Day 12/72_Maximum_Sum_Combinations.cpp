// Brute Force - TC: O(n^2)  SC: O(C)
// -----------------------------------
// We will use a double loop and then push the sum of A and B if the size of heap exceeds C we pop. Lastly we store our answer
// in ans vector and then reverse it and return.

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            pq.push(A[i] + B[j]);
            if (pq.size() > C)
                pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Optimised Approach - TC: O(nlogn)  SC: O(n)
// --------------------------------------------
// https://www.youtube.com/watch?v=btjG9eLNYcg&t=0s

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    priority_queue<pair<int, pair<int, int>>> hp;
    set<pair<int, int>> S;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    hp.push(make_pair(A[n - 1] + B[n - 1], make_pair(n - 1, n - 1)));
    S.insert(make_pair(n - 1, n - 1));

    vector<int> ans;
    int k = n;
    while (k--)
    {
        pair<int, pair<int, int>> top = hp.top();
        hp.pop();
        if (ans.size() == C)
        {
            return ans;
        }
        ans.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;

        if (R > 0 && L >= 0 && S.find(make_pair(L, R - 1)) == S.end())
        {
            hp.push(make_pair(A[L] + B[R - 1], make_pair(L, R - 1)));
            S.insert(make_pair(L, R - 1));
        }
        if (R >= 0 && L > 0 && S.find(make_pair(L - 1, R)) == S.end())
        {
            hp.push(make_pair(A[L - 1] + B[R], make_pair(L - 1, R)));
            S.insert(make_pair(L - 1, R));
        }
    }
    return ans;
}
