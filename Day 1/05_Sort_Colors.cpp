// Brute Force (Sorting) - TC: O(nlogn)  SC:(1)
// -----------------------------------------------
// Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the array would arrange the elements in increasing 
// order.

class Solution {
public:
    void sortColors(vector<int>& a) {
        sort(a.begin(), a.end());
    }
};


// Better Approach - TC: O(n + n) SC: O(1)
// -----------------------------------------
// 1. Take 3 variables to maintain the count of 0, 1 and 2.
// 2. Travel the array once and increment the corresponding counting variables
// ( let’s consider count_0 = a, count_1 = b, count_2 = c )

// 3. In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ 
// with ‘1’ and the remaining ‘c’ with ‘2’.

class Solution {
public:
    void sortColors(vector<int>& a) {
        int zero = 0, one = 0, two = 0;
        for(int i = 0;i<a.size();i++){
            if(a[i] == 0) zero++;
            else if(a[i] == 1) one++;
            else two++;
        }
        int i, j;
        for(i = 0;i<zero;i++) a[i] = 0;
        for(j = i;j<i+one;j++) a[j] = 1;
        for(int k = j;k<j + two;k++) a[k] = 2;
    }
};


// 3-Pointer Approach (Dutch National flag algorithm) - TC: O(n)  SC: O(1)
// ------------------------------------------------------------------------
// 1. Initialize the 3 pointers such that low and mid will point to 0th index and high pointer will point to last index
//     int low = arr[0]
//     int mid = arr[0]
//     int high = arr[n – 1]

// 2. Now there will 3 different operations / steps based on the value of arr[mid] and will be repeated until mid <= high.
// (i) arr[mid] == 0:
//     swap(arr[low], arr[mid])
//     low++, mid++

// (ii)arr[mid] == 1:
//     mid++

// (iii)arr[mid] == 2:
//     swap(arr[mid], arr[high])
//     high–;

// The array formed after these steps will be a sorted array.

class Solution {
public:
    void sortColors(vector<int>& a) {
        int low = 0;
        int high = a.size() - 1;
        int mid = 0;
        while(mid<=high){
            if(a[mid] == 0){
                swap(a[mid++],a[low++]);
            }
            else if(a[mid] == 1){
                mid++;
            }
            else {
                swap(a[mid],a[high--]);
            }
        }
    }
};