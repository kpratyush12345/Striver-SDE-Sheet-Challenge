// Brute Force - TC: O(n*log(n))+O(n)  SC: O(n)
// ----------------------------------------------
// 1. Declare a HashSet.
// 2. Run a for loop from starting to the end.
// 3. Put every element of the array in the set.
// 4. Store size of the set in a variable K.
// 5. Now put all elements of the set in the array from the starting of the array.
// 6. Return K.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i = 0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int j = 0;
        for (int x: s) {
            nums[j++] = x;
        }
        return s.size();
    }
};


// Two Pointer Approach - TC: O(n)  SC: O(1)
// --------------------------------------------
// 1. Take a variable i as 0;
// 2. Use a for loop by using a variable ‘j’ from 1 to length of the array.
// 3. If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
// 4. After completion of the loop return i+1, i.e size of the array of unique elements.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};