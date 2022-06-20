// Heap Approach - TC: O(n)  SC: O(k)
// ------------------------------------
// We will use min heap which will be having the minimum upwards. So when we push it inside the heap and then if size is greater
// than k then we'll pop it. Lastly we will have the kth largest at the top.

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> mh;
        for (int i = 0; i < nums.size(); i++)
        {
            mh.push(nums[i]);
            if (mh.size() > k)
                mh.pop();
        }
        return mh.top();
    }
};