// Recursive Approach - TC: O(N! x N)  SC: O(N)
// ----------------------------------------------
// We have given the nums array, so we will declare an ans vector of vector that will store all the permutations also declare 
// a data structure.

// Declare a map and initialize it to zero and call the recursive function

// When the data structure’s size is equal to n(size of nums array)  then it is a permutation and stores that permutation in 
// our ans, then returns it.

// Run a for loop starting from 0 to nums.size() – 1. Check if the frequency of i is unmarked, if it is unmarked then it 
// means it has not been picked and then we pick. And make sure it is marked as picked.

// Call the recursion with the parameters to pick the other elements when we come back from the recursion make sure you throw 
// that element out. And unmark that element in the map.

class Solution {
public:
    void recurPermute(vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans,vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds,nums,ans,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};


// Backtracking Approach - TC: O(N! x N)  SC: O(1)
// ------------------------------------------------
// We have given the nums array, so we will declare an ans vector of vector that will store all the permutations.

// Call a recursive function that starts with zero, nums array, and ans vector.

// Declare a map and initialize it to zero and call the recursive function

// Whenever the index reaches the end take the nums array and put it in ans vector and return.

// Go from index to n – 1 and swap. Once the swap has been done call recursion for the next state.After coming back from the 
// recursion make sure you re-swap it because for the next element the swap will not take place.

class Solution {
public:
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};