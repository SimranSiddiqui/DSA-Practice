class Solution {
    
    int func(vector<int>& coins, int target, int n, vector<vector<int>>& dp)
    {
        if(n < 0)
        {
            if(target == 0)
                return 1;
            return 0;
        }
        if(target < 0)
            return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int p = func(coins, target-coins[n], n, dp);
        int np = func(coins, target, n-1, dp);
        
        return dp[n][target] = p+np;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return func(coins, amount, n-1, dp);
    }
};