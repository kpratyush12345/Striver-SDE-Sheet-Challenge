// Brute Force - TC: O(n^2)  SC: O(1)
// -----------------------------------
// We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all 
// transactions.

// 1. Use a for loop of ‘i’ from 0 to n.
// 2. Use another for loop from ‘i+1’ to n.
// 3. If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
// 4. Return maxPro.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        for(int i = 0;i<prices.size();i++){
            for(int j = i+1;j<prices.size();j++){
                if(prices[j] > prices[i]){
                    mx = max(mx, prices[j] - prices[i]);
                }
            }
        }
        return mx;
    }
};

// Optimal Approach - TC: O(n)  SC: O(1)
// --------------------------------------
// We will linearly travel the array. We can maintain a minimum from the starting of the array and compare it with every 
// element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update 
// the minimum.

// 1. Create a variable maxPro and mark it as 0.
// 2. Create a variable minPrice and mark it as max_value.
// 3. Run a for loop from 0 to n.
// 4. Update the minPrice at if it greater than current element of the array
// 5. Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
// 6. Return the maxPro.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0;i < prices.size();i++){
            minPrice = min(minPrice , prices[i]);
            maxPro = max(maxPro , prices[i] - minPrice);
        }
        return maxPro;
    }
};