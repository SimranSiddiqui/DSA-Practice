
        class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        
        vector<vector<int>> dp(d+1, vector<int>(n + 1, INT_MAX));
        dp[0][n] = 0;

        for(int i = 1; i <= d; i++){
            for(int j = n-1; j >= 0; j--){
                int mx = 0;
                for(int k = j; k <= n-i; k++){
                    mx = max(mx, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], ((dp[i-1][k+1] == INT_MAX) ? INT_MAX : mx + dp[i-1][k+1]));
                }
            }
        }
        return dp[d][0];
    }
};
   