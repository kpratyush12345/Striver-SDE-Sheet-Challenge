// Brute Force - TC : O(n^2)  SC: O(k)
// ---------------------------------------
// We initially keep a left and right pointer to fix our window to a size of k. We compute the maximum element present in this
// window using the GetMax function. Further, update the left and right pointer by left++ and right++ every time to get to a new
// window of size k using a while loop. For every new window we encounter, we add the maximum element using the GetMax function
// to our data structure.

class Solution
{
public:
    void getMax(vector<int> nums, int l, int r, vector<int> &arr)
    {
        int i, maxi = INT_MIN;
        for (i = l; i <= r; i++)
            maxi = max(maxi, nums[i]);
        arr.push_back(maxi);
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        int i, j;
        vector<int> arr;
        while (right < k - 1)
        {
            right++;
        }
        while (right < nums.size())
        {
            getMax(nums, left, right, arr);
            left++;
            right++;
        }
        return arr;
    }
};

// Using Deque - TC: O(n)  SC: O(k)
// ------------------------------------
// We address this problem with the help of a data structure that keeps checking whether the incoming element is larger than the
// already present elements. This could be implemented with the help of a de-queue. When shifting our window, we push the new
// element in from the rear of our de-queue.
// Every time before entering a new element, we first need to check whether the element present at the front is out of bounds of
// our present window size. If so, we need to pop that out. Also, we need to check from the rear that the element present is
// smaller than the incoming element. If yes, there’s no point storing them and hence we pop them out. Finally, the element
// present at the front would be our largest element.

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};