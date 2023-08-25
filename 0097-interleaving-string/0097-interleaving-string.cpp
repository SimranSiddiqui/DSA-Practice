class Solution {
public:
    bool solve(string s1, string s2, string s3, int n, int m, int l, vector<vector<int>> &dp)
    {
        if(l < 0)
            return m<0 && n<0;
        if(m<0 && n<0)
            return false;
        
        if(n>=0 && m>=0 && dp[n][m] != -1)
            return dp[n][m];
        
        bool ans = false;
        
        if(m>=0 && s2[m] == s3[l])
            ans = ans || solve(s1, s2, s3, n, m-1, l-1, dp);
        if(n>=0 && s1[n] == s3[l])
            ans = ans || solve(s1, s2, s3, n-1, m, l-1, dp);
        
        if(n>=0 && m>=0)
            dp[n][m] = ans;
        
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i=0,k=0;i<=n;i++)
        {
            for(int j=0,k=i;j<=m;j++,k++)
            {
                if(i==0 && j==0) dp[i][j] = m+n == l;
                else if(i==0) dp[i][j] = dp[i][j-1] && s3[k-1]==s2[j-1];
                else if(j==0) dp[i][j] = dp[i-1][j] && s3[k-1]==s1[i-1];
                
                else
                dp[i][j] = (dp[i][j-1] && s3[k-1]==s2[j-1]) || (dp[i][j] = dp[i-1][j] && s3[k-1]==s1[i-1]);
            }
        }
        
        return dp[n][m];
    }
};