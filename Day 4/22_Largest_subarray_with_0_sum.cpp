// Brute Force - TC: O(n^2)  SC: O(1)
// -------------------------------------
// We use 2 loops and do sum if sum is 0 then we store the maximum length.

class Solution{
    public:
    int maxLen(vector<int>&a, int n){   
        int  mx = 0;
    	for(int i = 0; i < n; ++i){
    		int sum = 0;
    		for(int j = i; j < n; ++j){
    			sum += a[j];
    			if(sum == 0){
    				mx = max(mx, j-i+1);
    			}
    		}
    	}
    	return mx;
    }
};


// Optimised Approach - TC: O(n)  SC: O(n)
// ------------------------------------------
// 1. First let us initialise a variable say sum = 0 which stores the sum of elements traversed so far and another variable 
// say max = 0 which stores the length of longest subarray with sum zero.
// 2. Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as key and its index as value.
// 3. Now traverse the array, and add the array element to our sum. 
// (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0,so we update max with the 
// maximum value of (max, current_index+1)

// (ii)  If sum is not equal to zero then we check hashmap if we’ve seen a subarray with this sum before

// if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our 
// max 
// else -> Insert (sum, current_index) into hashmap to store prefix sum until current index

// After traversing the entire array our max variable has the length of longest substring having sum equal to zero, so 
// return max.
// NOTE : we do not update the index of a sum if it’s seen again because we require the length of the longest subarray

class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        unordered_map<int, int> presum; 
  
        int sum = 0; 
        int max_len = 0; 
    
        for (int i = 0; i < n; i++) { 
            sum += A[i]; 
      
            if (A[i] == 0 && max_len == 0) 
                max_len = 1; 
            if (sum == 0) 
                max_len = i + 1; 
    
            if (presum.find(sum) != presum.end()) { 
                max_len = max(max_len, i - presum[sum]); 
            } 
            else { 
                presum[sum] = i; 
            } 
        } 
        return max_len; 
    }
};