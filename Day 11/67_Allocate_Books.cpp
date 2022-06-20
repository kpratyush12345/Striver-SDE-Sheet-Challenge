// Binary Search - TC: O(nlogn)  SC: O(1)
// ---------------------------------------
// We will set a search space. The lower boundary will be of minimal value among all the books given. The upper boundary will
// be the sum of all book pages given. Then apply binary search. How to change the range of searching? While searching, allocate
// pages to each student in such a way that the sum of allocated pages of each student is not greater than the mid-value of
// search space. If allocating students increases more than the number of students provided, this shows that mid-value should
// be more, and hence, we move right by restricting our lower boundary as mid+1. If an allocation is possible then reduce the
// search upper boundary by mid-1. Also, an edge case to check while allocating, each book page should not be greater than
// mid-value chosen as a barrier.

int isPossible(vector<int> &A, int pages, int students)
{
    int cnt = 0;
    int sumAllocated = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (sumAllocated + A[i] > pages)
        {
            cnt++;
            sumAllocated = A[i];
            if (sumAllocated > pages)
                return false;
        }
        else
        {
            sumAllocated += A[i];
        }
    }
    if (cnt < students)
        return true;
    return false;
}

int books(vector<int> &A, int B)
{
    if (B > A.size())
        return -1;
    int low = A[0];
    int high = 0;
    for (int i = 0; i < A.size(); i++)
    {
        high = high + A[i];
        low = min(low, A[i]);
    }
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(A, mid, B))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
