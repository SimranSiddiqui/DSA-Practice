class Solution {
    
    long long solve(vector<vector<int>> &questions, long long &ans, int n, vector<long long> &dp)
    {
        if(n >= questions.size())
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        long long p = questions[n][0] + solve(questions, ans, n+questions[n][1]+1, dp);
        long long np = solve(questions, ans, n+1, dp);
        
        return dp[n] = max(p, np);
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long ans = 0;
        
        vector<long long> dp(n+1, -1);
        
        return solve(questions, ans, 0, dp);
        
    }
};