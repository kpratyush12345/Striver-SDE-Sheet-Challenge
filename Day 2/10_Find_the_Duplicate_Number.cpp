// Brute Force (Sorting Method) - TC: O(nlogn + n)  SC: O(1)
// ----------------------------------------------------------
// Sort the array. After that, if there is any duplicate number they will be adjacent.So we simply have to check if 
// arr[i]==arr[i-1] and if it is true,arr[i] is the duplicate number.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =1;i<nums.size();i++){
            if(nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};

// Using Frequency array or unordered_map - TC: O(n)  SC: O(n)
// ------------------------------------------------------------
// We use an extra map to store the frequency of elements and if any element has frequency greater than one we found the ans.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int duplicate = 0;
        for(auto i= 0; i<nums.size(); ++i) m[nums[i]]++;
        
        for(auto i : m){
            if(i.second > 1){
                duplicate = i.first;
                break;
            }
        }
        return duplicate;
    }
};


// Cyclic Sort Method - TC: O(n)  SC: O(1)
// -----------------------------------------
// In this approach we are given the value is from 1 to n, so we apply cyclic sort in which we place every element to its 
// correct position and check if arr[i] == arr[correct] then there is a match we return that element as our answer.

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] != i + 1) {
                int correct = arr[i] - 1;
                if (arr[i] != arr[correct]) {
                    swap(arr[i], arr[correct]);
                } else {
                    return arr[i];
                }
            } else {
                i++;
            }
        }
        return -1;
    }
};


// Slow Fast Pointer (Linked List cycle method) - TC: O(n)  O(1)
// ---------------------------------------------------------------
// Since there is a duplicate number, we can always say that cycle will be formed.

// The slow pointer moves by one step and the fast pointer moves by 2 steps and there exists a cycle so the first collision 
// is bound to happen.

// Let’s assume the distance between the first element and the first collision is a. So slow pointer has traveled a distance 
// while fast(since moving 2 steps at a time) has traveled 2a distance. For slow and a fast pointer to collide 2a-a=a should 
// be multiple of the length of cycle, Now we place a fast pointer to start. Assume the distance between the start and 
// duplicate to be x. So now the distance between slow and duplicate shows also be x, as seen from the diagram, and so now 
// fast and slow pointer both should move by one step.

//For better Explaination - https://youtu.be/32Ll35mhWg0

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
                     
        fast = nums [0];
        while(slow != fast){
            slow=nums[slow];  
            fast= nums [fast]; 
        }
        return slow;
    }
};