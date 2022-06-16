// Recursive Approach - TC: O((2^n) *k*(n/2))  SC: O(k*x) - k  is the average length, x is the no. of combinations
// -----------------------------------------------------------------------------------------------------------------
// The initial idea will be to make partitions to generate substring and check if the substring generated out of the 
// partition will be a palindrome. Partitioning means we would end up generating every substring and checking for palindrome 
// at every step. Since this is a repetitive task being done again and again, at this point we should think of recursion. The 
// recursion continues until the entire string is exhausted. After partitioning, every palindromic substring is inserted in a 
// data structure When the base case has reached the list of palindromes generated during that recursion call is inserted in 
// a vector of vectors/list of list.

class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void solve(int index,string s,vector<string> &path,vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i - index + 1));
                solve(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0,s,path,res);
        return res;
    }
};