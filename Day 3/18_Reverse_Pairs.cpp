// Brute Force - TC: O(n^2)  SC: O(1)
// ------------------------------------
// We will be having 2 nested For loops the outer loop having i as pointer 
// The inner loop with j as pointer and we will make sure that 0 <= i < j < arr.length() and also arr[i] > 2*arr[j] 
// condition must be satisfied.

class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int pairs = 0;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                if(arr[i] > 2 * arr[j]) pairs++;
            }
        }
        return pairs;
    }
};


// Merge Sort Approach - TC: O(nlogn) + O(n) + O(n)  SC: O(n)
// --------------------------------------------------------------
// It uses the same concept as Count inversions Problem just some conditions should be changed.
// For best Explaination : https://youtu.be/S6rsAlj_iB4

class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high) {
        int total = 0;
        int j = mid + 1;
        for(int i = low; i <= mid; i++) {
            while(j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            total += (j - (mid + 1));
        }

        vector<int> t;
        int left = low, right = mid + 1;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                t.push_back(nums[left++]);
            }
            else {
                t.push_back(nums[right++]);
            }
        }

        while(left <= mid) {
            t.push_back(nums[left++]);
        }
        while(right <= high) {
            t.push_back(nums[right++]);
        }

        for(int i = low; i <= high; i++) {
            nums[i] = t[i - low];
        }
        return total;
    }
    
    int mergeSort(vector<int> &nums, int low, int high) {
        if(low >= high) return 0;
        
        int mid = (low + high) / 2;
        int inv = mergeSort(nums, low, mid);
        inv += mergeSort(nums, mid + 1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }
    
    int reversePairs(vector<int> &nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};