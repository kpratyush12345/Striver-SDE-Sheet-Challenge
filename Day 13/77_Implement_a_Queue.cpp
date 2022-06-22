// TC: O(1)  SC: O(n)
// ---------------------
// The basic approach is to maintain two variables to point to the START and END of the filled elements in the array. START
// pointer is used to point to the starting index of the elements and the same case for the END pointer(ending index).
// Initially, both have value -1(indicating empty queue).

// First, let’s see the implementation of the push function. Push basically inserts a new element at the end. So only the END
// variable is going to be incremented.

// Corner case 1: What if we have no empty places in the array? So, first check that, if we don’t have we exit, in the other
// case we increment the START variable and put the new element.

// Corner case 2: What if END reaches the last index? We are doing mod with addition. So, END goes back to index 0([0-(n-1)]
// will always be the range for END).

// Second, let us see the pop function. In Queue pop removes and returns the front element. So, START needs to be modified. The
// general approach is to copy the current element pointed by START and increase the START variable to the next index.

// Corner case 3: What if the Queue is empty? That’s why we are checking the START variable. If it is -1, then the queue is
// empty, we just exit.

// Corner case 4: What if START goes out of bound? As done for END, mod addition comes to the rescue.

// Corner case 5: What happens after popping the last element? We check this state with the currSize variable. Queue returns to
// the initial state, both START and END are set to -1.

// Third, let’s see the top function. It behaves more like a pop function. We need to return the element pointed by the START
// variable. Since we are not actually removing any element, it’s fine to ignore corner cases 4 and 5.

class Queue
{
    int *arr;
    int first;
    int rear;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        first = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (first == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear == size)
        {
            cout << "Queue is full";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (first == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[first];
            arr[first] = -1;
            first++;
            if (first == rear)
            {
                first = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        // Implement the front() function
        if (rear == first)
        {
            return -1;
        }
        else
        {
            return arr[first];
        }
    }
};