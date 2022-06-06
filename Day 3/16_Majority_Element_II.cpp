// Brute Force - TC: O(n^2)  SC: O(1)
// ---------------------------------------
// Approach: Simply count the no. of appearance for each element using nested loops and whenever you find the count of 
// an element greater than N/3 times, that element will be your answer.

vector<int> majorityElement(vector<int>& arr) {
    int n = arr.size();
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i])
                cnt++;
        }
        if (cnt > (n / 3)) 
        ans.push_back(arr[i]);
    }
    return ans;
}


// Using Map - TC: O(n)  SC: O(n)
// -------------------------------
// Traverse the whole array and store the count of every element in a map. After that traverse through the map and whenever 
// you find the count of an element greater than N/3 times, store that element in your answer.

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map <int, int> mp;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        for (auto x: mp) {
            if (x.second > (n / 3))
                ans.push_back(x.first);
        }
        return ans;
    }
};


// Optimal Solution (Extended Boyer Moore’s Voting Algorithm) - TC: O(n)  SC: O(1)
// ----------------------------------------------------------------------------------
// In our code, we start with declaring a few variables:

// 1. num1 and num2 will store our currently most frequent and second most frequent element.
// 2. c1 and c2 will store their frequency relatively to other numbers.
// 3. We are sure that there will be a max of 2 elements which occurs > N/3 times because there cannot be if you do a 
// simple math addition.
// 4. Let, ele be the element present in the array at any index. 

//     if ele == num1, so we increment c1.
//     if ele == num2, so we increment c2.
//     if c1 is 0, so we assign num1 = ele.
//     if c2 is 0, so we assign num2 = ele.
//     In all the other cases we decrease both c1 and c2.
// In the last step, we will run a loop to check if num1 or nums2 are the majority elements or not by running a for loop 
// check.

// Intuition: Since it’s guaranteed that a number can be a majority element, hence it will always be present at the last 
// block, hence, in turn, will be on nums1 and nums2. For a more detailed explanation, please watch the video below.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
        for (i = 0; i < sz; i++) {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0) {
                num1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                num2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        vector < int > ans;
        count1 = count2 = 0;
        for (i = 0; i < sz; i++) {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
        }
        if (count1 > sz / 3)
            ans.push_back(num1);
        if (count2 > sz / 3)
            ans.push_back(num2);
        return ans;
    }
};