// Optimal Approach - TC: O(numRows^2)  SC: O(numRows^2)
// -------------------------------------------------------
// To solve the problem, we need to first create a 2D ans vector. This ans vector is used to store each of the rows expected 
// in the output, so, for example, ans[1] = [1,1]. In this array, the number of columns (say, numCols) is equal to the number 
// of the i-th row + 1 (Since, 0-indexed), i.e., for 0-th row, numCols = 1. So, the number of columns is different for each 
// row.
// Next, we need to run a loop from i = 0 to numRows in order to store each row in our ans vector. For each of iteration of 
// this loop, we follow the below steps:

// 1. Create a temp array of size (i + 1) .
// 2. Set all the values of temp array to 1. We can do both steps by simply using vector<int> temp(i+1,1).
// 3. Run another loop from j = 1 to i  and for each iteration put temp[j] = ans[i-1][j] + ans[i-1][j-1];.
// After iterating numRows times, you return the array.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0;i<numRows;i++){
            vector<int> temp(i+1,1);
            for(int j = 1;j < i ;j++){
                temp[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};