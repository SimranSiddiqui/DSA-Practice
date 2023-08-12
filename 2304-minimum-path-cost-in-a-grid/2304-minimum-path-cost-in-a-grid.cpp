class Solution {
public:
    
    int solve(vector<vector<int>> &grid, vector<vector<int>> &cost, int m, int n, vector<vector<int>> &dp)
    {
        if(m == grid.size()-1)
            return grid[m][n];
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int ans = INT_MAX;
        for(int i=0;i<grid[0].size();i++)
        {
            int j = grid[m][n];
            ans = min(ans, solve(grid, cost, m+1, i, dp) + cost[j][i] + j);
        }
        
        return dp[m][n] = ans;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0;i<n;i++)
        {
             ans = min(ans, solve(grid, moveCost, 0, i, dp));
        }
        
        return ans;
    }
};