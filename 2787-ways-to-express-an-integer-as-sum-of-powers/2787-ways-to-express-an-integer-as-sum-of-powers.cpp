#define mod 1000000007
class Solution {
public:
    int power(int n, int x)
    {
        int ans = 1;
        while(x--)
        {
            ans = (ans%mod * n%mod)%mod;
        }
        
        return ans;
    }
    int solve(int m, int n, int x, vector<vector<int>> &dp)
    {
        if(n == 0)
            return 1;
        if(n < 0 || m <= 0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = solve(m-1, n - power(m, x), x, dp)%mod + solve(m-1, n, x, dp)%mod;
    }
    int numberOfWays(int n, int x) {
        int m = n;
        if(x != 1)
        m = sqrt(n);
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, x, dp);
    }
};