// Brute Force - TC: O(n^2)  SC: O(1)
// -----------------------------------
// Check the count of occurrences of all elements of the array one by one. Start from the first element of the array and 
// count the number of times it occurs in the array. If the count is greater than the floor of N/2 then return that element 
// as the answer. If not, proceed with the next element in the array and repeat the process.


// Using Map - TC: O(n)  SC: O(n)
// -------------------------------
// Use a hashmap and store as (key,value) pairs. (Can also use frequency array based on size of nums) 
// Here the key will be the element of the array and value will be the number of times it occurs. 
// Traverse the array and update the value of the key. Simultaneously check if the value is greater than floor of N/2. 
//     If yes, return the key 
//     Else iterate forward. 


// Moore’s Voting Algorithm - TC: O(n)  SC: O(1)
// -------------------------------------------------
// Intuition: The question clearly states that the nums array has a majority element. Since it has a majority element we can 
// say definitely the count is more than N/2.

// Majority element count = N/2 + x;

// Minority/Other elements = N/2 – x;

// Where x is the number of times it occurs after reaching the minimum value N/2.

// Now, we can say that count of minority elements and majority element are equal upto certain point of time in the array. 
// So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. 
// Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the 
// majority element. 

// Approach: 
// 1. Initialize 2 variables: 
//     Count –  for tracking the count of element
//     Element – for which element we are counting
// 2. Traverse through nums array.
//     If Count is 0 then initialize the current traversing integer of array as Element 
//     If the traversing integer of array and Element are same increase Count by 1
//     If they are different decrease Count by 1
// 3. The integer present in Element is the result we are expecting 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int candidate =0;
        
        for(int num: nums){
            if(count == 0) candidate = num;
            if(num==candidate) count++;
            else count--;
        }
        return candidate;
    }
};