// Brute Force - TC: O(n*m*(n+m) + n*m)  SC: O(1)
// ----------------------------------------------
// Assuming all the elements in the matrix are non-negative. Traverse through the matrix and if you find an element with 
// value 0, then change all the elements in its row and column to -1, except when an element is 0. The reason for not 
// changing other elements to 0, but -1, is because that might affect other columns and rows. Now traverse through the 
// matrix again and if an element is -1 change it to 0, which will be the answer.

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    for(int k = 0;k<m;k++){
                        if(mat[i][k] != 0)
                            mat[i][k] = -1;
                    }
                    for(int k = 0;k<n;k++){
                        if(mat[k][j] != 0)
                            mat[k][j] = -1;
                    }
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == -1) 
                    mat[i][j] = 0;
            }
        }
    }
};


// Better Approach - TC: O(n*m + n*m)  SC: O(n)
// ---------------------------------------------
// Take two dummy array one of size of row and other of size of column.Now traverse through the array.If matrix[i][j]==0 
// then set dummy1[i]=0(for row) and dummy2[j]=0(for column).Now traverse through the array again and 
// if dummy1[i]==0  || dummy2[j]==0 then arr[i][j]=0,else continue.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector < int > row(r,-1), col(c,-1);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }

        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (row[i] == 0 || col[j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// Optimised Approach - TC: O(2*(n*m))  SC: O(1)
// ------------------------------------------------
// Instead of taking two separate dummy array,take first row and column of the matrix as the array for checking whether 
// the particular column or row has the value 0 or not.Since matrix[0][0] are overlapping.Therefore take separate variable 
// col(say) to check if the 0th column has 0 or not and use matrix[0][0] to check if the 0th row has 0 or not.Now traverse 
// from last element to the first element and check if matrix[i][0]==0 || matrix[0][j]==0 and if true set matrix[i][j]=0,
// else continue.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int col = 1;
        int row = n;
        int m = matrix[0].size();
        for(int i = 0;i<n;i++){
            if(matrix[i][0] == 0) col = 0;
            for(int j = 1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=1;j--)
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j]=0;
            }   
            if(col==0) matrix[i][0]=0;
        }
    }
};