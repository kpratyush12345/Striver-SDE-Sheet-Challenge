// TC: O(n)  SC: O(n)
// -----------------------
// Take a single queue.
// push(x): Push the element in the queue.
// Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element
// becomes the most former element and vice versa.
// pop(): remove the element from the queue.
// top(): show the element at the top of the queue.
// size(): size of the current queue.

#include <bits/stdc++.h>
class Stack
{
    queue<int> q;
    int siz;

public:
    Stack()
    {
        siz = -1;
    }

    int getSize()
    {
        return q.size();
    }

    bool isEmpty()
    {
        return (q.empty());
    }

    void push(int element)
    {
        siz++;
        q.push(element);
        for (int i = 0; i < siz; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (!q.empty())
        {
            int popped = q.front();
            q.pop();
            siz--;
            return popped;
        }
        return -1;
    }

    int top()
    {
        if (!q.empty())
            return q.front();
        return -1;
    }
};