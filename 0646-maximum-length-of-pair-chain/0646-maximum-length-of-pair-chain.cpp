class Solution {
    
    int solve(vector<vector<int>>& pairs, int curr, int n, vector<vector<int>> &dp)
    {
        if(n<0)
            return 0;
        if(dp[n][curr] != -1)
            return dp[n][curr];
        
        int p=-1, np=-1;
        
        if(curr==pairs.size() || pairs[n][1] < pairs[curr][0])
            p = solve(pairs, n, n-1, dp) +1;
        np = solve(pairs, curr, n-1, dp);
        
        return dp[n][curr] = max(np, p);
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(pairs, n, n-1, dp);
    }
};