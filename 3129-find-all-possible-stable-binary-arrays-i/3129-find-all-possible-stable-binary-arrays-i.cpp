#define mod 1000000007
class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;
    int solve( int zero, int one, int limit, int prev, int len){
        if(!zero && !one){
            return 1;
        }
        if(dp[zero][one][prev][len] != -1)
            return dp[zero][one][prev][len];
        
        int ans = 0;
        if(len == limit){
            if(prev == 1 && zero){
                ans = (ans + solve( zero-1, one, limit, 0, 1))%mod;
            }
            else if(prev == 0 && one)
            {
                ans = (ans + solve( zero, one-1, limit, 1, 1))%mod;
            }
            else
                return 0;
        }
        else{
        if(one){
            if(prev == 0)
            ans = (ans + solve( zero, one-1, limit, 1, 1))%mod;
            else
            ans = (ans + solve( zero, one-1, limit, 1, len+1))%mod;   
        }
        if(zero){
            if(prev == 1)
            ans = (ans + solve( zero-1, one, limit, 0, 1))%mod;
            else
            ans = (ans + solve( zero-1, one, limit, 0, len+1))%mod;
        }
        }
        return dp[zero][one][prev][len] = ans%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        bool flag = true;
        int prev = 2;
        int len = 0;
        
        dp = vector<vector<vector<vector<int>>>> (zero+1, vector<vector<vector<int>>>(one+1, vector<vector<int>>(3, vector<int>(limit+1, -1))));
        return solve( zero, one, limit, prev, len);
    }
};