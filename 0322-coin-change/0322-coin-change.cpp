class Solution {
    
    long func(vector<int>& coins, int target, int n, vector<vector<int>>& dp)
    {
        if(n < 0)
        {
            if(target==0)
                return 0;
            else
                return INT_MAX;
        }
        
        if(target < 0)
        {
            return INT_MAX;
        }
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        long p = func(coins, target-coins[n], n, dp) +1 ;
        long np = func(coins, target, n-1, dp) ;
        
        return dp[n][target] = min(p, np);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        
        int ans= func(coins, amount, n-1, dp);
        
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};