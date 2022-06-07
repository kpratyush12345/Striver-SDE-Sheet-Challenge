// For Better Explaination : https://youtu.be/t_f0nwwdg5o
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Brute Force (Recursive Solution) - TC: Exponential  SC: Exponential (due to stack space)
// -----------------------------------------------------------------------------------------
// As we are only allowed to go down or right, so as we know in recursion it checks each and every case. So we will call 
// countPaths(i+1,j,n,m) for right and countPaths(i,j+1,n,m) for down and when we reach the i == n -1 or j == m - 1 we return 1 
// as we know in the last row and last column there's only one way. So everytime we return the values of 
// countPaths(i+1,j,n,m) + countPaths(i,j+1,n,m) and finally we get the number of paths. One extra boundary case is when i or j
// exceeds there limit we return 0.

class Solution {
public:
    int countPaths(int i,int j,int n,int m){
        if(i==(n-1) && j==(m-1)) return 1;
        if(i>=n || j>=m) return 0;
        
        return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    
    int uniquePaths(int m, int n) {
        return countPaths(0,0,m,n);
    }
};


// DP Memoized Approach - TC: O(n*m)  SC: O(n*m)
// ---------------------------------------------------------
// We have just memoized the above approach. When we are doing a recursion call we will just store it in a 2D dp, as we know 
// in recursion the same case can also be checked more than once so we store it and keep a check if(dp[i][j] != -1) return dp[i][j]
// by this whenever a same call is called it checks if its already in dp and if it is then we simply return its value. Lastly we 
// have our answer stored in dp[0][0].

class Solution {
public:
    int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp) {
        if(i == (n-1) && j == (m-1)) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = countPaths(i+1,j,n,m,dp) + countPaths(i,j+1,n,m,dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int num = countPaths(0,0,m,n,dp);
        if(m==1 && n==1) return num;
        return dp[0][0];
    }
};

// Dynamic Programming Approach - TC: O(n*m)  SC: O(m*n)
// --------------------------------------------------------
// This is a Pure DP Solution in which we initialize the first row and column with 1, and then loop through and do 
// dp[i][j]=dp[i-1][j]+dp[i][j-1] which will add all the possible path of that column by adding the possible paths on the top
// and left of that dp. And finally we get our answer at dp[n-1][m-1].

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        dp[0][0]=1;
        
        for(int i=1;i<m;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};


// Combinatorics Approach - TC: O(m - 1) or O(n - 1)  SC: O(1)
// -------------------------------------------------------------
// If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number 
// of steps to reach the end.

// From start to reach the end we need a certain number of rightward directions and a certain number of downward directions. 
// So we can figure out we need n-1 no. of rightward direction and m-1 no. of downward direction to reach the endpoint.

// Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 
// downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1; //or we can also use n - 1
        double res = 1;
            
        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        
        return (int)res;
    }
};