// Brute Force - TC: O(N log N + N³ logN)  SC: (M*4)
// ----------------------------------------------------
// The main idea is to sort the array, and then we can think of searching in the array using the binary search technique. 
// Since we need the 4 numbers which sum up to target. So we will fix three numbers as nums[i], nums[j] and nums[k], and 
// search for the remaining (target – (nums[i] + nums[j] + nums[k])) in the array. Since we sorted the array during the 
// start, we can apply binary search to search for this value, and if it occurs we can store them. In order to get the 
// unique quads, we use a set data structure to store them.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> sv;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){ 
                   int x = (long long)target - (long long)nums[i] - (long long)nums[j]-(long long)nums[k];
                
                    if(binary_search(nums.begin()+k+1,nums.end(),x)){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(x);
                        sort(v.begin(),v.end());
                        sv.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> res(sv.begin(),sv.end());
        return res;
    }
};


// Optimized Approach - TC: O(N log N + N^2 logN)  SC: O(M*4)
// -------------------------------------------------------------
// Sort the array, and then fix two pointers, so the remaining sum will be (target – (nums[i] + nums[j])). Now we can fix 
// two pointers, one front, and another back, and easily use a two-pointer to find the remaining two numbers of the quad. 
// In order to avoid duplications, we jump the duplicates, because taking duplicates will result in repeating quads. We can 
// easily jump duplicates, by skipping the same elements by running a loop.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        int n = num.size();
        vector<vector<int>> res;
        if(num.empty()) return res;
        sort(num.begin(),num.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target_2 = target - num[j] - num[i];
                int front = j+1;
                int back = n-1;
                while(front<back){
                    int two_sum = num[front] + num[back];
                    if(two_sum < target_2) front++;
                    else if(two_sum > target_2) back--;
                    else{
                        vector<int> quadruplet(4,0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                        
                        while(front<back && num[front] == quadruplet[2]) ++front;
                        while(front<back && num[back] == quadruplet[3]) --back;
                    }
                }
                while(j+1<n && num[j+1] == num[j]) ++j;
            }
            while(i+1<n && num[i+1]==num[i]) ++i;
        }
        return res;
    }
};