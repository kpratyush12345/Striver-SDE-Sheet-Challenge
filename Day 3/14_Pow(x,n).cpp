// Brute Force - TC: O(n)  SC: O(1)
// -----------------------------------
// What is wrong with this approach? the range of int is between -2147483647 to 2147483648 So if we change the negative to 
// positive then we have to store it in a diffrent variable i.e. long long int and if n is negative the as we know it is like 
// x^(-n) = 1/(x^n)  So lastly if n is negative we do 1.0/ans and return.

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int m = n;
        if(n < 0){
            m = -1 * m;
        }
        for(int i = 0;i < m;i++) {
            ans = ans*x;
        }
        if(n < 0){
            ans = 1.0/ans;
        }
        return ans;
    }
};

// Binary Exponentiation Approach - TC: O(logn)  SC: O(1)
// --------------------------------------------------------
// Initialize ans as 1.0  and store a duplicate copy of n i.e m using to avoid overflow

// Check if m is a negative number, in that case, make it a positive number.

// Keep on iterating until m is greater than zero, now if m is an odd power then multiply x with ans ans reduce m by 1. 
// Else multiply x with itself and divide m by two.

// Now after the entire binary exponentiation is complete and m becomes zero, check if n is a negative value we know the 
// answer will be 1 by and.

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long m = n;
        if (m < 0) m = -1 * m;
        while(m > 0) {
            if(m % 2 == 1) {
                ans = ans * x;
                m--;
            } 
            else {
                x = x * x;
                m /= 2;
            }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};