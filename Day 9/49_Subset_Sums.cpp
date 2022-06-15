// Recursive Approach - TC: O(2^n)+O(2^n log(2^n))  SC: O(2^n)
// ------------------------------------------------------------
// Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e add the element 
// to the sum or don’t pick and move to the next element, recursively, until the base condition. Here when you reach the 
// end of the array is the base condition.

class Solution {
public:
    void solve(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
        if (ind == n) {
            ans.push_back(sum);
            return;
        }
        //element is picked
        solve(ind + 1, arr, n, ans, sum + arr[ind]);
        //element is not picked
        solve(ind + 1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N){
        vector <int> ans;
        solve(0, arr, N, ans, 0);
        return ans;
    }
};