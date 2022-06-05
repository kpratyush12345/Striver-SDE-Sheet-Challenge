// Optimal Approach - TC: O(nlogn + n)  SC: O(n*n)
// -------------------------------------------------
// Linearly iterate over the array if the data structure is empty insert the interval in the data structure. If the last 
// element in the data structure overlaps with the current interval we merge the intervals by updating the last element in 
// the data structure, and if the current interval does not overlap with the last element in the data structure simply insert 
// it into the data structure.

// Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on 
// merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply 
// inserted the element in our data structure.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0) {
            return mergedIntervals; 
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0]; 
        
        for(auto it : intervals) {
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]); 
            } else {
                mergedIntervals.push_back(tempInterval); 
                tempInterval = it; 
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};