class Solution {
    
    int func(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp)
    {
        if(n == 0 && m==0 && grid[n][m] == 0)
            return 1;
        if(n == 0 && m==0 && grid[n][m] == 1)
            return 0;
        if(m < 0 || n < 0)
            return 0;
        if(grid[n][m] == 1)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        return dp[n][m] = func(grid, n-1, m, dp) + func(grid, n, m-1, dp);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return func(obstacleGrid, n-1, m-1, dp);
    }
};