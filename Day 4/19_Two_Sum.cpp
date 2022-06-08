// Brute Force - TC: O(n^2)  SC: O(1)
// -----------------------------------
// We will just use 2 loops and if nums[i] + nums[j] == target we return the i and j index as our answer.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }
};


// Two Pointer Approach - TC: O(nlogn)  SC: O(n)
// ---------------------------------------------------
// We create a copy of the array nums, lets suppose it as store array now we sort it and keep 2 pointers left and right and 
// check if left and right elements sums up to target if not check is it greater than target then we have to reduce it so 
// the greater is at the right side so we do right-- else left-- and if we find it equal we store it inside 2 elements n1 and 
// n2. Now we have to traverse and check if nums[i] == n1 or nums[i] == n2 then we push it in answer and return. 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res,store;
    	store = nums;

    	sort(store.begin(), store.end());
    	int left=0,right=nums.size()-1;
    	int n1,n2;
    	while(left<right){
        	if(store[left]+store[right]==target){
            	n1 = store[left];
            	n2 = store[right];
            	break;
        	}
        	else if(store[left]+store[right] > target) right--;
        	else left++;
    	}
    	for(int i=0;i<nums.size();++i){
        	if(nums[i]==n1) res.push_back(i);
        	else if(nums[i]==n2) res.push_back(i);
    	}
    	return res;
    }
};


// Using Map - TC: O(n)  SC: O(n)
// ---------------------------------
// Loop through the array and if the target - nums[i] is not present then add it inside the map and in map the key is the array 
// element and value is the index of that array. And if target - nums[i] is present the we return the index of both.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0;i < nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {mp[target-nums[i]], i};
            }
            else mp[nums[i]] = i;
        }
        return {};
    }
};