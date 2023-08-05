class Solution {
    
    int solve(int m, int n, vector<vector<int>> &dp)
    {
        if(!m || !n)
            return 0;
        if(m == 1 && n == 1)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = solve(m-1, n, dp) + solve(m, n-1, dp);
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(m, n, dp);
    }
};