#define mod 1000000007
class Solution {
public:
    
    int solve(int target, vector<vector<int>>& types, int n,  vector<vector<long long>> &dp)
    {
        if(target == 0)
            return 1;
        if(target < 0 || n<0)
            return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target]%mod;
        
        long long ans=0;
        
       /* if(types[n][0] > 0){
            types[n][0]--;
            ans += solve(target-types[n][1], types, n);
            types[n][0]++;
        }*/
        
        for(int i=0;i<=types[n][0];i++)
        {
            ans += solve(target-types[n][1]*i, types, n-1, dp)%mod;
        }
      //  ans += solve(target, types, n-1);
        
        return dp[n][target] = ans%mod;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return solve(target, types, n-1, dp);
    }
};