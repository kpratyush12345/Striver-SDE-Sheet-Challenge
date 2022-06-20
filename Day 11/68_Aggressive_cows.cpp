// Binary Search Approach - TC: O(nlogn)  SC: O(1)
// ----------------------------------------------------
// Make sure to sort the array first, because only then it makes sense to use binary search.

// For the BS approach, we set low = 1 because the minimum distance is 1 and high =array[n-1] – array[0] . because that’s
// the maximum possible distance between two stalls.

// Let’s calculate our mid-value after this.

//             mid = low + (high-low)/2

// Then we check if the minimum distance(mid-value) is possible by the same method defined in brute force, and if it is not
// possible, this means we can set our upper bound as high-1, and if it is possible, we store it in an answer variable and
// set our lower bound as mid+1. We keep on doing this until high and low pointers are equal.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool canPlaceCows(int arr[], int n, int cows, int dist)
{
    int coord = arr[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - coord >= dist)
        {
            count++;
            coord = arr[i];
        }
        if (count == cows)
            return true;
    }
    return false;
}
int largestmindist(int a[], int n, int cows)
{
    int low = 1;
    int high = a[n - 1] - a[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (canPlaceCows(a, n, cows, mid))
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        cout << largestmindist(a, n, c) << endl;
    }
    return 0;
}