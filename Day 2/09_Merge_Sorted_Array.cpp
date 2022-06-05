// Brute Force - TC: O(mlogm)+O(m)+O(n)  SC: O(n + m)
// ---------------------------------------------------
// 1. Make an arr of size n+m.
// 2. Put elements arr1 and arr2 in arr.
// 3. Sort the arr.
// 4. Now first fill the arr1 and then fill remaining elements in arr2.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr(n+m);
        int k = 0;
        for(int i = 0; i < m; i++) {
            arr[k++] = nums1[i];
        }
        for(int i = 0; i < n; i++) {
            arr[k++] = nums2[i];
        }
        sort(arr.begin(),arr.end());
        nums1 = arr;
    }
};


// Better Approach - TC: O(n + m)  SC: O(1)
// ------------------------------------------
// We will keep a k pointer at n+m-1 which is the last index of nums1 array then we traverse both the arrays and check if 
// nums1[i] >= nums2[j] then we add the i element to kth index and dcrement i else we add j element and decrement j and in each
// step we will decrement k after filling it. Lastly some values might be left in the nums2 array so we push everything.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = n+m-1;
        while(i>=0 && j>=0) {
            if(nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i--];
            }
            else {
                nums1[k] = nums2[j--];
            }
            k--;
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }      
    }
};


// Gap Method - TC: O(logm)  SC: O(1)
// ------------------------------------
// 1. Initially take the gap as (m+n)/2;
// 2. Take as a pointer1 = 0 and pointer2 = gap.
// 3. Run a oop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
// 4. After completion of the loop reduce the gap as gap=gap/2.
// 5. Repeat the process until gap>0.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = ceil((float)(n + m) / 2);
        while (gap > 0) {
            int i = 0;
            int j = gap;
            while (j < (n + m)) {
                if (j < m && nums1[i] > nums1[j]) swap(nums1[i], nums1[j]);
                else if (j >= m && i < m && nums1[i] > nums2[j - m]) swap(nums1[i], nums2[j - m]);
                else if (j >= m && i >= m && nums2[i - m] > nums2[j - m]) swap(nums2[i - m], nums2[j - m]);
                j++;
                i++;
            }
            if (gap == 1) gap = 0;
            else gap = ceil((float) gap / 2);
        }
        //Now all the nums1 and nums2 is sorted so we can add the contents of nums2 at the end of nums1
        int j = 0;
        for(int i = m;i<n+m;i++){
            nums1[i] = nums2[j++];
        }
    }
};