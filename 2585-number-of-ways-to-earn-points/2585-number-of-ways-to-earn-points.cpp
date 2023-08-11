#define mod 1000000007
class Solution {
public:
    
    int solve(int target, vector<vector<int>>& types, int n, int i,  vector<vector<vector<long long>>> &dp)
    {
        if(target < 0 || n<0 || i > types[n][0])
            return 0;
        if(target == 0){
            //cout << target << endl;
            return 1;
        }
        
        if(dp[n][target][i] != -1)
            return dp[n][target][i]%mod;
        
        long long ans=0;
        
       /* for(int i=0;i<=types[n][0];i++)
        {
            ans += solve(target-types[n][1]*i, types, n-1, dp)%mod;
        }*/
        
        ans += solve(target-types[n][1], types, n, i+1, dp)%mod;
        ans += solve(target, types, n-1, 0, dp)%mod;
        //cout << ans << endl;
        
        return dp[n][target][i] = ans%mod;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(target+1, vector<long long>(51, -1)));
        int i = types[n-1][0];
        return solve(target, types, n-1, 0, dp)%mod;
    }
};