class Kthlargest
{
public:
    priority_queue<int, vector<int>, greater<int>> q;
    Kthlargest(int k, vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
            q.push(arr[i]);
    }

    void add(int num)
    {
        if (num <= q.top())
            return;
        q.push(num);
        q.pop();
    }

    int getKthLargest()
    {
        return q.top();
    }
};