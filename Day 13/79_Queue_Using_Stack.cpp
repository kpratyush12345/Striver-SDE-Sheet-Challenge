// Using two Stacks where push operation is O(N) - TC: O(n)  SC: O(2n)
// ---------------------------------------------------------------------
class Queue
{
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        // Implement the enqueue() function.
    }

    int deQueue()
    {
        int ans;
        if (s1.empty())
            return -1;
        else
        {
            ans = s1.top();
            s1.pop();
        }
        return ans;
        // Implement the dequeue() function.
    }

    int peek()
    {
        if (s1.empty())
            return -1;
        else
            return s1.top();
        // Implement the peek() function here.
    }

    bool isEmpty()
    {
        if (s1.empty())
            return true;
        else
            return false;
        // Implement the isEmpty() function here.
    }
};

// Using two Stacks where push operation is O(1) - TC: O(1)  SC: O(2n)
// ---------------------------------------------------------------------

class Queue
{
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (s1.empty())
        {
            return -1;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int peek()
    {
        // Implement the peek() function here.
        if (s1.empty())
        {
            return -1;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        // s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return s1.empty();
    }
};

// For Better Explaination - https://youtu.be/3Et9MrMc02A