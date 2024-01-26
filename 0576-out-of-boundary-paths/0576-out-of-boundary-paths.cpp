#define mod 1000000007
class Solution {
public:
    int solve(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>> &dp)
    {
        if(!maxMove)
            return row<0 || row>=m || col<0 || col>=n;
        if(row<0 || row>=m || col<0 || col>=n)
            return 1;
        if(dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];
        
        int a = solve(m, n, maxMove-1, row-1, col, dp) + solve(m, n, maxMove-1, row+1, col, dp);
        int b = solve(m, n, maxMove-1, row, col-1, dp) + solve(m, n, maxMove-1, row, col+1, dp);
        
        return dp[row][col][maxMove] = (a%mod + b%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};