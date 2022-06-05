// Brute Force - TC: O(n*n)  SC: O(n*n)
// ---------------------------------------
// Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the 
// dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n,vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};


// Optimised Approach - TC: O(n*n)  SC: O(1)
// -------------------------------------------
// Step1: Transpose of the matrix. (transposing means changing columns to rows and rows to columns)
// Step2: Reverse each row of the matrix.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int k = 0;
        for(int i = 0;i<matrix.size();i++){
            for(int j = k;j<matrix[i].size();j++){
                swap(matrix[i][j], matrix[j][i]);
            }
            k++;
        }
        
        for(int i = 0;i<matrix.size();i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};