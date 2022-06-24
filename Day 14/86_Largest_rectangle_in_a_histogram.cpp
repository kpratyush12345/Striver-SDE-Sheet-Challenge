// Brute Force - TC: O(n^2)  SC: O(n)
// ------------------------------------
// The approach is to find the right smaller and left smaller element and find the largest Rectangle area in Histogram.

class Solution
{
public:
    int largestRectangleArea(vector<int> &arr)
    {
        int n = arr.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int minHeight = INT_MAX;
            for (int j = i; j < n; j++)
            {
                minHeight = min(minHeight, arr[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        return maxArea;
    }
};

// Optimised Approach - TC: O(n)  SC: O(3n)
// --------------------------------------------
// The intuition behind the approach is the same as finding the smaller element on both sides but in an optimized way using
// the concept of the next greater element and the next smaller element.

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                rightsmall[i] = n - 1;
            else
                rightsmall[i] = st.top() - 1;

            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxA;
    }
};

// Stack Approach - TC: O(N)  SC: O(N)
// -----------------------------------
// This approach is a single pass approach instead of a two-pass approach. When we traverse the array by finding the next
// greater element, we found that some elements were inserted into the stack which signifies that after them the smallest
// element is themselves

// So we can find the area of the rectangle by using arr[i] * (right smaller – left smaller -1 ).

class Solution
{
public:
    int largestRectangleArea(vector<int> &histo)
    {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
            {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};
