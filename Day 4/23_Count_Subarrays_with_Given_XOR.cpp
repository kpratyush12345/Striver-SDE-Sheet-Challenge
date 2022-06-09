// Brute Force - TC: O(n^2)  SC: O(1)
// ---------------------------------------
// Generate subarrays: To generate all possible subarrays, we use the same old technique of nested loops. For each value of 
// the outer loop (i loop), the inner loop(j loop) runs from i till the last element. Each iteration of the inner loop gives 
// a new subarray. 
// Maintain XOR: Since each iteration of the inner loop gives a new subarray, we maintain a variable X, in which we keep the 
// XOR of the current subarray. 
// Check and Count: Before moving to the next iteration of the inner loop (that is before going to the next subarray), we 
// check if the current XOR is equal to B, if it is then we increment the counter (counter also has to be maintained).

int subarraysXor(vector<int> &arr, int x){
    long long c=0;
    for(int i=0;i<arr.size();i++){
        int current_xor = 0;
        for(int j=i;j<arr.size();j++){
            current_xor ^= arr[j];
            if(current_xor == x) c++;
        }
    }
    return c;
}

// Prefix XOR and Map - TC: O(n)  SC: O(n)
// -------------------------------------------
// We need to traverse the array while we maintain variables for current_perfix_xor, counter, and also a map to keep track 
// of visited xors. This map will maintain the frequency count of all previous visited current_prefix_xor values. If for any 
// index current_prefix_xor is equal to B, we increment the counter. If for any index we find that Z is present in the freq 
// map, we increment the counter by freq[Z] (Z=current_prefi_xor^B). At every index, we insert the current_prefix_xor into 
// the freq map with its frequency.

// For Best Explaination : https://youtu.be/lO9R5CaGRPY

int subarraysXor(vector<int> &arr, int x){
    map<int,int> freq;
    int cnt = 0;
    int xorr = 0;
    for(auto it: arr){
        xorr = xorr ^ it;
        if(xorr == x) cnt++;
        if(freq.find(xorr ^ x) != freq.end())
            cnt += freq[xorr ^ x];
        freq[xorr] += 1;
    }
    return cnt;
}