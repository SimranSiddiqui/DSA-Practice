class Solution {
public:
    int solve(string text1, string text2, int n1, int n2, vector<vector<int>> &dp)
    {
        if(n1<0 || n2<0)
            return 0;
        
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
        
        if(text1[n1] != text2[n2])
            return dp[n1][n2] = max(solve(text1, text2, n1-1, n2, dp), solve(text1, text2, n1, n2-1, dp));
        else
            return dp[n1][n2] = solve(text1, text2, n1-1, n2-1, dp)+1;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    
            }
        }
        
        return dp[n1][n2];
    }
};