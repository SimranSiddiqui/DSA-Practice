class Solution {
public:
    
    int solve(vector<int> &piles, int al, int bob, int i, int j, int turn, vector<vector<int>> &dp)
    {
        if(i > j)
            return al > bob;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(turn%2 == 0)
            return dp[i][j] = solve(piles, al+piles[i], bob, i+1, j, turn+1, dp) || solve(piles, al+piles[j], bob, i, j-1, turn+1, dp);
        
        return dp[i][j] = solve(piles, al, bob+piles[i], i+1, j, turn+1, dp) || solve(piles, al, bob+piles[j], i, j-1, turn+1, dp);
    }
    
    bool stoneGame(vector<int>& piles) {
        int al = 0, bob = 0;
        int n = piles.size();
        int i=0, j=n-1;
        int turn = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(piles, al, bob, i, j, turn, dp);
    }
};