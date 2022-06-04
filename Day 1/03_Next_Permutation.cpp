// Brute Force (Backtracking Method) - TC: O(n!*n)  SC: O(n)
// ------------------------------------------------------------
// Step 1: Find all possible permutations of elements present and store them in ans 2D vector.
// Step 2: Sort the vector and search for the nums vector.
// Step 3: When we find the nums in ans 2D vector and if i != n then simply copy the ans[i + 1] to nums and if i == n then we
// know we have that searched permutation at the end and as per the question we have to return the first permutation so we do
// that.

void permute(vector<vector<int>> &ans, vector<int> &arr, int l, int r){
	if (l == r)
		ans.push_back(arr);
	else {
		// Permutations made
		for (int i = l; i <= r; i++){
			// Swapping done
			swap(arr[l], arr[i]);
			// Recursion called
			permute(ans, arr, l+1, r);
			//backtrack
			swap(arr[l], arr[i]);
		}
	}
}

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
	permute(ans, nums, 0, n-1);
	sort(ans.begin(), ans.end());
	for(int i =0;i<ans.size();i++){
	    if(ans[i] == nums){
	        if(i != ans.size() - 1)
	            nums = ans[i + 1];
	        else
	            nums = ans[0];
	        break;
	    }
	}
}


// Using C++ Build-in function
// ----------------------------
// C++ provides an in-built function called next_permutation() which directly returns the lexicographically next greater 
// permutation of the input.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};


// Optimised Approach - TC: O(3*n)  SC: O(1)
// -------------------------------------------
// Step 1: Linearly traverse array from backward such that ith index value of the array is less than (i+1)th index value. 
// Store that index in a variable.

// Step 2: If the index value received from step 1 is less than 0. This means the given input array is the largest 
// lexicographical permutation. Hence, we will reverse the input array to get the minimum or starting permutation. 
// Linearly traverse array from backward. Find an index that has a value greater than the previously found index. 
// Store index another variable.

// Step 3: Swap values present in indices found in the above two steps.

// Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
    	for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
    	if (i < 0) reverse(nums.begin(), nums.end());
        else {
            int j;
    	    for(j = n - 1; j > i; j--) {
                if(nums[j] > nums[i]) {
                    break;
                }
            } 
    	    swap(nums[i], nums[j]);
    	    reverse(nums.begin() + i + 1, nums.end());
        }
    }
};