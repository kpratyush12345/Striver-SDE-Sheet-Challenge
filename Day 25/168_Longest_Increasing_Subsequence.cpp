int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int siz = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            siz++;
        }
        else
        {
            int inx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[inx] = arr[i];
        }
    }
    return siz;
}