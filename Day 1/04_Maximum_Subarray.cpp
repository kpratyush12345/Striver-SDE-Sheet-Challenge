// Naive Approach - TC: O(n^3)  SC: O(1)
// ---------------------------------------
// Using three for loops, we will get all possible subarrays in two loops and their sum in another loop, and 
// then return the maximum of them.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            for(int j = i;j<nums.size();j++){
                int sum = 0;
                for(int k = i;k<=j;k++){
                    sum += nums[k];
                }
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};


// Better Approach - TC: O(n^2)  SC: O(1)
// ----------------------------------------
// We can also do this problem using only two for loop, starting the function with ( max_sum ) variable which will have 
// the final answer. We can get the sum of all possible subarrays in this way and then return the maximum so far.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            for(int j = i;j<nums.size();j++){
                sum += nums[j];
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};


// Optimal Approach (Using Kadane's Algorithm) - TC: O(n)  SC: O(1)
// -----------------------------------------------------------------
// As we need maximum subarray sum so while iterating if we come across sum subarray sum that is lesser than 0 then we make 
// the sum to 0, so that while taking the next subarray sum we get maximum sum. Parallely we will take the max of sum in each 
// iteration. Finally we get the maximum sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = INT_MIN;
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            mx = max(mx, sum);
            if(sum < 0) sum = 0;
        }
        return mx;
    }
};