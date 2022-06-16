// Recursive Approach - TC: O(2^n * k)  SC: O(k*x) - k is the average length x is the no. of combinations
// ------------------------------------------------------------------------------------------------------
// Before starting the recursive call make sure to sort the elements because the ans should contain the combinations in 
// sorted order and should not be repeated.

// Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element of our subsequence.

// Check if the current index value can be added to our ds. If yes add it to the ds and move the index by 1. while moving 
// the index skip the consecutive repeated elements because they will form duplicate sequences.

// Reduce the target by arr[i],call the recursive call for f(idx + 1,target – 1,ds,ans) after the call make sure to pop the 
// element from the ds.(By seeing the example recursive You will understand).

// if(arr[i] > target) then terminate the recursive call because there is no use to check as the array is sorted in the next 
// recursive call the index will be moving by 1 all the elements to its right will be in increasing order.

class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>>& ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        } 
        for(int i = ind;i<arr.size();i++){
            if(i>ind && arr[i] == arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombination(i+1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};