// Brute Force - TC: O(n^2)  SC: O(1)
// ------------------------------------
// For each index, we have to find the amount of water that can be stored and we have to sum it up. If we observe 
// carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and 
// right of the index minus the elevation at that index.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            int leftMax = 0, rightMax = 0;
            while (j >= 0) {
                leftMax = max(leftMax, height[j]);
                j--;
            }
            j = i;
            while (j < n) {
                rightMax = max(rightMax, height[j]);
                j++;
            }
            waterTrapped += min(leftMax, rightMax) - height[i];
        }
        return waterTrapped;
    }
};


// Using Prefix and Suffix Arrays - TC: O(3*n)  SC: O(n + n)
// ----------------------------------------------------------
// Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand.Then use the 
// formula min(prefix[i],suffix[i])-arr[i] to compute water trapped at each index

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n], suffix[n];
        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            waterTrapped += min(prefix[i], suffix[i]) - height[i];
        }
        return waterTrapped;
    }
};

// Two Pointer Approach - TC: O(n)  SC: O(1)
// -------------------------------------------
// Take 2 pointer l(left pointer) and r(right pointer) pointing to 0th and (n-1)th index respectively.Take two variables 
// leftMax and rightMax and initialise it to 0.If heigh[l] is less than or equal to height[r] then if leftMax is less then 
// height[l] update leftMax to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the 
// right i.e l++.If height[r] is less then height[l],then now we are dealing with the right block.If height[r] is greater 
// then rightMax,then update rightMax to height[r] else add rightMax-height[r] to the final answer.Now move r to the left.
// Repeat theses steps till l and r crosses each other.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int maxLeft = 0, maxRight = 0;
        while(left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) maxLeft = height[left];
                else res += maxLeft - height[left];
                left++;
            }
            else {
                if (height[right] >= maxRight) maxRight = height[right];
                else res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};