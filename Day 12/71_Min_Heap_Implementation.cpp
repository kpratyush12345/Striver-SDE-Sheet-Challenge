// Using Heap - TC: O(n)  SC: O(n)
// ---------------------------------
// We are given a 2d Matrix and when the 1st index is 0 then we insert the element of the 2nd index and side by side push every
// element inside the answer vector.

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (q[i][0] == 0)
        {
            pq.push(q[i][1]);
        }
        else
        {
            if (!pq.empty())
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
    }
    return ans;
}
