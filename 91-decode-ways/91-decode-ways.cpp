class Solution {
    
    int count(int n, string &s, int* dp)
    {
        if(dp[n] != -1)
            return dp[n];
        
        if(n >= s.size())
        {
            return 1;
        }
        
        int ans =0;
        int n1 = s[n] - '0';
        int n2 = 0;
        
        if(n<s.size()-1)
        {
            n2 = n1*10 + s[n+1]-'0';
        }
        
        if(n1>0)
           ans += count(n+1, s,dp);
        
        if(n1>0 && n2>0 && n2 <= 26)
           ans += count(n+2, s,dp);
        
        return dp[n] = ans;
        
    }
    
public:
    int numDecodings(string s) {
        int dp[s.length()+1];
        memset(dp,-1,sizeof dp);
        return count(0,s,dp);
    }
};