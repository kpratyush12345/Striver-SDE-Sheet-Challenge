// Sorting Method - TC: O(2*nlogn) + O(n)  SC: O(1)
// --------------------------------------------------
// At first we need to sort both the arrays. When the events will be sorted, it will be easy to track the count of 
// trains that have arrived but not departed yet. Total platforms needed at one time can be found by taking the 
// difference of arrivals and departures at that time and the maximum value of all times will be the final answer. 
// If(arr[i]<=dep[j]) means if arrival time is less than or equal to the departure time then- we need one more platform. 
// So increment count as well as increment i. If(arr[i]>dep[j]) means arrival time is more than the departure time then- 
// we have one extra platform which we can reduce. So decrement count but increment j. Update the ans with max(ans, count) 
// after each iteration of the while loop.

class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n){
    	sort(arr, arr + n); 
        sort(dep, dep + n); 
    
        int plat_needed = 1, res = 1; 
        int i = 1, j = 0; 
     
        while (i < n && j < n) { 
            if (arr[i] <= dep[j]) { 
                plat_needed++; 
                i++; 
            }
            else if (arr[i] > dep[j]) { 
                plat_needed--; 
                j++; 
            } 
    
            if (plat_needed > res) 
                res = plat_needed; 
        } 
      
        return res; 
    }
};