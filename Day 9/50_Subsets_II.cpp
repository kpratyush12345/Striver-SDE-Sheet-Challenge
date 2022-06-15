// Brute Force - TC: O(2^n + mlogm)  SC: O(2^n * m) - m is size of set
// ---------------------------------------------------------------------
// At every index, we make a decision whether to pick or not pick the element at that index. This will help us in 
// generating all possible combinations but does not take care of the duplicates. Hence we will use a set to store all the 
// combinations that will discard the duplicates.

class Solution {
public:
    void fun(vector<int> & nums, int index, vector<int> ds, set <vector<int>> & res) {
        if (index == nums.size()) {
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);
        ds.pop_back();
        fun(nums, index + 1, ds, res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        fun(nums, 0, ds, res);
        for(auto i : res){
            ans.push_back(i);
        }
        return ans;
    }
};

// Optimal Approach - TC: O(2^n)  SC: O(2^n^m) - m is size of subset generated after every base case
// --------------------------------------------------------------------------------------------------- 
//  - Sort the input array.Make a recursive function that takes the input array ,the current subset,the current index and a 
//  list of list/ vector of vectors to contain the answer.
//  - Try to make a subset of size n during the nth recursion call and consider elements from every index while generating 
//  the combinations. Only pick up elements that are appearing for the first time during a recursion call to avoid duplicates.
//  - Once an element is picked up, move to the next index.The recursion will terminate when the end of array is reached.
//  While returning backtrack by removing the last element that was inserted.

class Solution {
public:
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};