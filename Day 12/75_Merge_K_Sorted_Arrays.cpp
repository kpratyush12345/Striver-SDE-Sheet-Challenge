// Using Heap - TC: O(n*k)  SC: O(n^2)
// ---------------------------------------
// We will iterate over the matrix and store all the ements inside the min heap and then we will pop elements of heap ans store
// it in res and return.

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < kArrays[i].size(); j++)
        {
            minh.push(kArrays[i][j]);
        }
    }
    vector<int> res;
    while (minh.size() > 0)
    {
        res.push_back(minh.top());
        minh.pop();
    }
    return res;
}