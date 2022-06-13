// Brute Force - TC: O(n^3)  SC: O(3*k) - k is the no.of triplets
// ---------------------------------------------------------------
// We keep three-pointers i,j, and k. For every triplet we find the sum of A[i]+A[j]+A[k]. If this sum is equal to 
// zero, we’ve found one of the triplets. We add it to our data structure and continue with the rest.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        set<vector<int>> s;
        int l=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                       s.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        for(auto x: s){
           v.push_back(x);
        }
        return v;
    }
};


// Optimised Approach - TC: O(n^2)  SC: O(k)
// ---------------------------------------------
// We could make use of the fact that we just need to return the triplets and thus could possibly sort the array. This 
// would help us use a modified two-pointer approach to this problem.
// We are fixing the i pointer and then applying the traditional 2 pointer approach to check whether the sum of three 
// numbers equals zero. If the sum is less than zero, it indicates our sum is probably too less and we need to 
// increment our j pointer to get a larger sum. On the other hand, if our sum is more than zero, it indicates our sum 
// is probably too large and we need to decrement the k pointer to reduce the sum and bring it closer to zero.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<(int)nums.size()-2;i++){
            if(i == 0||(i > 0 && nums[i] != nums[i-1])){
                int l = i + 1, h = (int)nums.size() - 1, sum = -nums[i];  
                while(l<h){
                    if(nums[l] + nums[h] == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        res.push_back(temp);
                        while(l<h && nums[l]==nums[l+1]) l++;
                        while(l<h && nums[h]==nums[h-1]) h--;
                        l++;h--;
                    }
                    else if(nums[l]+nums[h]<sum) l++;
                    else h--;
                }
            }
        }
        return res;
    }
};
