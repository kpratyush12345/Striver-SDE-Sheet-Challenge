// Brute Force - TC: O(m+n)  SC: O(m+n)
// --------------------------------------
// ake two pointers, each pointing to each array. Take an array of size (m+n) to store the final sorted array. If the first
// pointed element is smaller than the second one, store that value in an array and move the first pointer ahead by one. Else
// do the same for the second pointer when the case is vice-versa. Then use the formula to get the median position and return
// the element present at that position.

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int finalArray[n + m];
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                finalArray[k++] = nums1[i++];
            }
            else
            {
                finalArray[k++] = nums2[j++];
            }
        }
        if (i < m)
        {
            while (i < m)
                finalArray[k++] = nums1[i++];
        }
        if (j < n)
        {
            while (j < n)
                finalArray[k++] = nums2[j++];
        }
        n = n + m;
        if (n % 2 == 1)
            return finalArray[((n + 1) / 2) - 1];

        else
            return ((double)finalArray[(n / 2) - 1] + (double)finalArray[(n / 2)]) / 2;
    }
};

// Binary Search Approach - TC: O(log(m,n))  SC: O(1)
// ----------------------------------------------------
// We will do a binary search in one of the arrays which have a minimum size among the two.

// Firstly, calculate the median position with (n+1)/2. Point two-pointer, say low and high, equal to 0 and size of the array
// on which we are applying binary search respectively. Find the partition of the array. Check if the left half has a total
// number of elements equal to the median position. If not, get the remaining elements from the second array. Now, check if
// partitioning is valid. This is only when l1<=r2 and l2<=r1. If valid, return max(l1,l2)(when odd number of elements present)
// else return (max(l1,l2)+min(r1,r2))/2.

// If partitioning is not valid, move ranges. When l1>r2, move left and perform the above operations again. When l2>r2, move
// right and perform the above operations.

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1); // ensuring that binary search happens on minimum size array

        int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = medianPos - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 != 0)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};