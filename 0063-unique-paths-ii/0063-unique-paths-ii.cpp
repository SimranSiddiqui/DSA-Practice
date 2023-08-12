class Solution {
    
    int solve(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if(m<0 || n<0)
            return 0;
        if(grid[m][n] == 1)
            return 0;
        if(!m && !n)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = solve(grid, m-1, n, dp) + solve(grid, m, n-1, dp);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(obstacleGrid, m-1, n-1, dp);
    }
};