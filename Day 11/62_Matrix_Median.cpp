// Brute Force - TC: O(n*m*log(n*m))  SC: O(n*m)
// -----------------------------------------------
// So here we will create an ans array and push all the elements inside it and then sort it and find the size/2 element and
// return.

int findMedian(vector<vector<int>> &matrix)
{
    vector<int> ans;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }

    sort(ans.begin(), ans.end());
    int m = ans.size() / 2;
    int x = ans[m];
    return x;
}

// Binary Search Approach - TC: O(row*log(col))  SC: O(1)
// -------------------------------------------------------
// Step 1: Find the minimum and maximum element in the given array. By just traversing the first column, we find the minimum
// element and by just traversing the last column, we find the maximum element.

// Step 2: Now find the middle element of the array one by one and check in the matrix how many elements are present in the
// matrix.

// Three cases can occur:-
//  - If count ==  (r*c+1)/2 , so it may be the answer still we mark max as mid since we are not referring indices , we are
// referring the elements and 5 elements can be smaller than 6 also and 7 also , so to confirm we mark max as mid.
//  - If count<(r*c+1)/2 , we mark  min as mid+1 since curr element or elements before it cannot be the answer.
//  - If count>(r*c+1)/2 , we mark max as mid , since elements after this can only be the  answer now.

int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}

int findMedian(vector<vector<int>> &A)
{
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(A[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
