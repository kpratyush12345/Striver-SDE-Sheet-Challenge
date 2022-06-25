// Using Stack - TC: O(1)  SC: O(n)
// -----------------------------------
// Push every pair of <price, result> to a stack.
// Pop lower price from the stack and accumulate the count.

class StockSpanner
{
public:
    stack<pair<int, int>> s;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int k = 1;
        while (!s.empty() && price >= s.top().first)
        {
            k += s.top().second;
            s.pop();
        }
        s.push({price, k});
        return k;
    }
};