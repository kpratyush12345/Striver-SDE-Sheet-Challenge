// Optimised Approach - TC: O(NlogN) + O(N*M)  SC: O(M) - M is max deadline
// ----------------------------------------------------------------------------
// The strategy to maximize profit should be to pick up jobs that offer higher profits. Hence we should sort the jobs 
// in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, but it 
// is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other 
// jobs.

// Basic Outline of the approach:-

// 1. Sort the jobs in descending order of profit. 
// 2. If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have 
// been performed yet.
// 3. For every job check if it can be performed on its last day.
// 4. If possible mark that index with the job id and add the profit to our answer. 
// 5. If not possible, loop through the previous indexes until an empty slot is found.

class Solution {
    public:
    static bool comparison(Job a, Job b){
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, comparison);
        int mx = arr[0].dead;
        for(int i=1;i<n;i++){
            mx = max(mx,arr[i].dead);
        }
 
        bool slot[mx+1]; 
        for (int i=0; i<mx; i++) slot[i] = false;
        
        int countJobs=0,jobProfit=0;
        for (int i=0; i<n; i++){
            for (int j= arr[i].dead; j>0; j--){
                if (slot[j]==false){
                    slot[j] = true;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    } 
};