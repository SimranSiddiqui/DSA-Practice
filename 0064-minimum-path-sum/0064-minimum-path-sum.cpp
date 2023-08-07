class Solution {
    
    int solve(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(n==0 && m==0)
            return grid[n][m];
        else if(n < 0 || m<0)
            return 1000;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        return dp[n][m] = min(solve(n-1, m, grid, dp)+grid[n][m], solve(n, m-1, grid, dp)+grid[n][m]);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(n-1, m-1, grid, dp);
    }
};