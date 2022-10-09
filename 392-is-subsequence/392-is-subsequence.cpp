class Solution {
public:
    
    bool dynamic(string t, string s, int n1, int n2, vector<int> &dp)
    {
        if(n1>=0 && n2==0)
            return true;
        else if(n1 == 0)
            return false;
        
        if(dp[n1] != -1)
            return dp[n1];
        
        if(t[n1-1] == s[n2-1])
            return dp[n1] = dynamic(t, s, n1-1, n2-1, dp);
        
        return dp[n1] = dynamic(t, s, n1-1, n2, dp);
    }
    
    bool isSubsequence(string s, string t) {
        int n1 = t.length();
        int n2 = s.length();
         
        vector<int> dp(n1+1, -1);
        
       return dynamic(t, s, n1, n2, dp);
        
    }
};