// Linear Search Approach - TC: O(n)  SC: O(1)
// ---------------------------------------------
// We will iterate through the array completely. While iterating, we have to check if we have found the target element in the
// array. If we find it, we will return its index. If we iterate completely and still do not find an element in the array. This
// indicates the target is not present and hence we return -1 as mentioned in the question.

int search(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

// Binary Search Approach - TC: O(logn)  SC: O(1)
// -----------------------------------------------
// We divide the array into parts. It is done using two pointers, low and high, and dividing the range between them by 2.
// This gives the midpoint of the range. Check if the target is present in the midpoint, calculated before, of the array. If
// not present, check if the left half of the array is sorted. This implies that binary search can be applied in the left half
// of the array provided the target lies between the value range. Else check into the right half of the array. Repeat the above
// steps until low <= high. If low > high, indicates we have searched array and target is not present hence return -1. Thus, it
// makes search operations less as we check range first then perform searching in possible ranges which may have target value.

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] == target)
                return mid;

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && nums[mid] >= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};