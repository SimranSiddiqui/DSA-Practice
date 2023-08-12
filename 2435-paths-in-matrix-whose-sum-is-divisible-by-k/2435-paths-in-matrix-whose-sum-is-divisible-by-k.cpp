#define mod 1000000007
#define ll long long
class Solution {
public:
    
    ll solve(vector<vector<int>> &grid, int m, int n, int k, ll sum, vector<vector<vector<int>>> &dp)
    {
        if(m<0 || n<0)
            return 0;
        if(m == 0 && n == 0)
        {
             return (sum+grid[m][n])%k == 0;   
        }
        
        if(dp[m][n][sum%k] != -1)
            return dp[m][n][sum]%mod;
        
        return dp[m][n][sum%k] = solve(grid, m-1, n, k, (sum+grid[m][n])%k, dp)%mod + solve(grid, m, n-1, k, (sum+grid[m][n])%k, dp)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        ll sum =0;
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(grid, m-1, n-1, k, sum, dp)%mod;
    }
};