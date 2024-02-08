class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp)
    {
        if(n == 0)
        {
            return 0;
        }
        if(n < 0 || m == 0)
        {
            return 1000;
        }
        if(dp[n][m] != -1)
            return dp[n][m];
        
        return dp[n][m] = min(solve(m, n - pow(m , 2), dp) + 1, solve(m-1, n, dp));
    }
    int numSquares(int n) {
        int m = ceil(sqrt(n));
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(m, n, dp);
    }
};