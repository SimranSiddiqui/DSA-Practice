#define mod 1000000007
class Solution {
public:
    vector<int> dRow = {1, 0, -1, 0};
    vector<int> dCol = {0, -1, 0, 1};
    
    int solve(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>> &dp)
    {
        if(!maxMove)
            return row<0 || row>=m || col<0 || col>=n;
        if(row<0 || row>=m || col<0 || col>=n)
            return 1;
        if(dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];
        
        int ans=0;
        for(int i=0;i<4;i++)
        {
            ans = (ans%mod + solve(m, n, maxMove-1, row+dRow[i], col+dCol[i], dp)%mod)%mod;
        }
        
        return dp[row][col][maxMove] = ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};