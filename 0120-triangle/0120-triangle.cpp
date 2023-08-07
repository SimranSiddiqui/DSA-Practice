class Solution {
    
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if(i >= triangle.size())
            return 0;
        if(j > triangle[i].size())
            return 1000;
        
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        
        return dp[i][j] = min(solve(i+1, j, triangle, dp)+triangle[i][j], solve(i+1, j+1, triangle, dp)+triangle[i][j]);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        
        return solve(0, 0,  triangle, dp);
    }
};