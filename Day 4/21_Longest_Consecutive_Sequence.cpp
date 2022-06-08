// Brute Force - TC: O(nlogn) + O(n)  SC: O(1)
// ---------------------------------------------
// Sort and find the consecutive longest sequence and return maximum of it.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 ) return 0;
        sort(nums.begin(),nums.end());
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};


// Using Set - TC: O(n)  SC: O(n)
// -------------------------------
// Put all the nums vector inside the set and while iterating check if num - 1 is not present therefore it is the first smallest 
// part of that subsequence and then we do a while loop and check if num + j is present then do j++ and store longest among 
// them and return.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int longest = 0;
        for(auto& num : s) {
            if(s.count(num - 1)) continue;
            int j = 1;
            while(s.count(num + j)) j++;
            longest = max(longest, j);
        }
        return longest;
    }
};