// Brute Force - TC: O(m*n)  SC: O(1)
// ------------------------------------
// We can traverse through every element that is present in the matrix and return true if we found any element in the matrix 
// is equal to the target integer. If the traversal is finished we can directly return false as we did not find any element in 
// the matrix to be equal to the target integer.



// Optimised (Binary Search) Approach - TC: O(log(m*n))  SC: O(1)
// ---------------------------------------------------------------
// As it is clearly mentioned that the given matrix will be row-wise and column-wise sorted, we can see that the elements in 
// the matrix will be in a monotonically increasing order. So we can apply binary search to search the matrix. Consider the 2D 
// matrix as a 1D matrix having indices from 0 to (m*n)-1 and apply binary search.

// i) Initially have a low index as the first index of the considered 1D matrix(i.e: 0) and high index as the last index of 
// the considered 1D matrix(i.e: (m*n)-1).

// ii) Now apply binary search. Run a while loop with the condition low<=high. Get the middle index as (low+high)/2.We can 
// get the element at middle index using matrix[middle/m][middle%m].

// iii) If the element present at the middle index is greater than the target, then it is obvious that the target element 
// will not exist beyond the middle index. So shrink the search space by updating the high index to middle-1. 

// iv) If the middle index element is lesser than the target, shrink the search space by updating the low index to middle+1.

// v) If the middle index element is equal to the target integer, return true.

// vi) Once the loop terminates we can directly return false as we did not find the target element.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = (n*m) -1;
        
        while(start<=end){
            int mid = start + (end - start)/2;
            if(matrix[mid/m][mid%m] == target) return true;
            if(matrix[mid/m][mid%m] < target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};