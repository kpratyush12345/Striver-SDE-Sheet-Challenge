// Recursive Approach - TC: O(2^t * k)  SC: O(k*x) - t is the target, k is the average length x is the no. of combinations
// ------------------------------------------------------------------------------------------------------------------------
// Initially, the index will be 0, target as given and the data structure(vector or list) will be empty

// Now there are 2 options viz to pick or not pick the current index element.

// If you pick the element, again come back at the same index as multiple occurrences of the same element is possible so the 
// target reduces to target – arr[index] (where target -arr[index]>=0)and also insert the current element into the data structure.

// If you decide not to pick the current element, move on to the next index and the target value stays as it is. Also, the 
// current element is not inserted into the data structure.

// While backtracking makes sure to pop the last element as shown in the recursion tree below.

// Keep on repeating this process while index < size of the array for a particular recursion call.

// You can also stop the recursion when the target value is 0, but here a generalized version without adding too many 
// conditions is considered.

// Using this approach, we can get all the combinations.

class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>>& ans, vector<int>& ds){
        if(ind == arr.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombination(ind + 1, target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};