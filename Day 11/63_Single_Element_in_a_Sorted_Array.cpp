// Using XOR - TC: O(N)  SC: O(1)
// -------------------------------
// As every number in the array repeats twice and only one number occurs once, we can take advantage of the XOR(^) operator.
// These are two properties of the XOR operator which will be helpful.
// If p is a number then,
// p^p=0
// p^0=p
// If we find the XOR of every element of the array, we will get the answer.

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int elem = 0;
        for (int i = 0; i < n; i++)
        {
            elem = elem ^ nums[i];
        }
        return elem;
    }
};

// Binary Search Approach - TC: O(logn)  SC: O(1)
// -----------------------------------------------
// As the elements are sorted, the left array will have twice values and right will also have twice value and in somewhere in
// the middle lies one unique element.
// Now in this left array, the first instance of every element is occurring on the even index and the second instance on the odd
// index. Similarly in the right array, the first instance of every element is occurring on the odd index and the second index
// is occurring on the even index.
// So the algorithmic approach will be to use binary search. The intuition is that when we see an element, if we know its index
// and whether it is the first instance or the second instance, we can decide whether we are presently in the left array or
// right array. Moreover, we can decide which direction we need to move to find the breakpoint. We need to find this breakpoint
// between our left array and the right array.
// We will check our mid element, if it is in the left array, we will shrink our left array to the right of this mid element, if
// it is in the right array, we will shrink the right array to the left of this mid element. This binary search process will
// continue till the right array surpasses our left one and the low is pointing towards the breakpoint.

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (mid % 2 == 0)
            {
                // Checking whether we are in right half
                if (nums[mid] != nums[mid + 1])
                    high = mid - 1; // Shrinking the right half
                else
                    low = mid + 1; // Shrinking the left half
            }
            else
            {
                // Checking whether we are in right half
                if (nums[mid] == nums[mid + 1])
                    high = mid - 1; // Shrinking the right half
                else
                    low = mid + 1; // Shrinking the left half
            }
        }
        return nums[low];
    }
};