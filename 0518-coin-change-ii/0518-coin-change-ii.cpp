class Solution {
    
    int solve(int n, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        if(amount == 0)
            return 1;
        if(amount < 0)
            return 0;
        if(n < 0){
            return 0;
        }
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        int pick =0, nPick=0;
        pick = solve(n, coins, amount-coins[n], dp);
        nPick = solve(n-1, coins, amount, dp);
        
        return dp[n][amount] = pick + nPick ;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, coins, amount, dp);
    }
};