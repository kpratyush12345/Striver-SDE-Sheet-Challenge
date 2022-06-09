// Brute Force - TC: O(n^2)  SC: O(n)
// ------------------------------------
// This approach consists of taking the two loops one for traversing the string and another loop – nested loop for finding 
// different substrings and after that, we will check for all substrings one by one and check for each and every element if 
// the element is not found then we will store that element in HashSet otherwise we will break from the loop and count it.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        for(int i = 0; i < s.length(); i++){
            unordered_set<char> set;
            for(int j = i; j < s.length(); j++){
                if(set.find(s[j]) != set.end()){
                    mx = max(mx, j - i);
                    break;
                }
                set.insert(s[j]);
            }
        }
        return mx;
    }
};

// Better Approach (Sliding Window) - TC: O(2*n)  SC: O(n)
// ---------------------------------------------------------
// We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of substring while 
// ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate 
// occurrence of the current element if found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        unordered_set<char> set;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            if(set.find(s[r]) != set.end()){
                while(l < r && set.find(s[r]) != set.end()) {
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};

// Optimised Approach (Sliding Window) - TC: O(n)  SC: O(n)
// -----------------------------------------------------------
// In this approach, we will make a map that will take care of counting the elements and maintaining the frequency of each 
// and every element as a unity by taking the latest index of every element.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while(right < n) {
            if(mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left);

            mpp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};