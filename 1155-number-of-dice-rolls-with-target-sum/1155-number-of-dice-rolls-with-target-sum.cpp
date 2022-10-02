class Solution {
    
    int recursiveCount(int n, int faces, int target, vector<vector<int>> &dp)
    {
        if(n==0 && target ==0)
        {
            return 1;
        }
        if(n==0 && target!=0)
        {
            return 0;
        }
        if(target ==0 && n!=0)
        {
            return 0;
        }
        if(target<0)
        {
             return 0;
        }
          
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int ans =0;
        for(int i=1;i<=faces;i++)
        {
            ans = ans%1000000007 + (recursiveCount(n-1, faces, target-i, dp)%1000000007);
        }
        
        return dp[n][target] = ans%1000000007;
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        return recursiveCount(n, k, target, dp);
    }
};