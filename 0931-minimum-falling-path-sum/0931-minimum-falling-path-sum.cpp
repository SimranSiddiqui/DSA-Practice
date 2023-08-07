class Solution {
    
    int solve(int n, int m, vector<vector<int>> &matrix, vector<vector<long>> &dp)
    {
        if(n<0)
            return 0;
        if( m<0 || m >= matrix[0].size())
            return 100000;
        
        if(dp[n][m] != INT_MAX)
            return dp[n][m];
        
        return dp[n][m] = min(solve(n-1, m-1, matrix, dp)+matrix[n][m], min(solve(n-1, m+1, matrix, dp)+matrix[n][m], solve(n-1, m, matrix, dp)+matrix[n][m]));
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        
        vector<vector<long >> dp(n, vector<long >(m, INT_MAX));
        for(int i=m-1;i>=0;i--)
        {
            ans = min(ans, solve(n-1, i, matrix, dp));
        }
        
        return ans;
    }
};