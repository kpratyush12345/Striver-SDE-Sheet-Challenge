// Brute Force - TC: O(k)  SC: O(1)
// ---------------------------------
// We will keep two pointers, say p1 and p2, each in two arrays. A counter to keep track of whether we have reached the kth
// position. Start iterating through both arrays. If array1[p1] < array2[p2], move p1 pointer ahead and increase counter value.
// If array2[p2] <array1[p1], move p2 pointer ahead and increase counter. When the count is equal to k, return the element in
// which condition makes the counter value equal to k.

class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {

        int p1 = 0, p2 = 0, counter = 0, answer = 0;

        while (p1 < m && p2 < n)
        {
            if (counter == k)
                break;
            else if (arr1[p1] < arr2[p2])
            {
                answer = arr1[p1];
                ++p1;
            }
            else
            {
                answer = arr2[p2];
                ++p2;
            }
            ++counter;
        }
        if (counter != k)
        {
            if (p1 != m - 1)
                answer = arr1[k - counter];
            else
                answer = arr2[k - counter];
        }
        return answer;
    }
};

// Binary Search Approach - TC: O(log(min(m,n)))  SC: O(1)
// -------------------------------------------------------
// Apply binary search in an array with a small size. Start iterating with two pointers, say left and right. Find the middle of
// the range. Take elements from low to middle of array1 and the remaining elements from the second array. Then using the
// condition mentioned above, check if the left half is valid. If valid, print the maximum of both array’s last element. If not,
// move the range towards the right if l2 > r1, else move the range towards the left if l1 > r2.

class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {

        if (m > n)
        {
            return kthElement(arr2, arr1, n, m, k);
        }

        int low = max(0, k - m), high = min(k, n);

        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 1;
    }
};