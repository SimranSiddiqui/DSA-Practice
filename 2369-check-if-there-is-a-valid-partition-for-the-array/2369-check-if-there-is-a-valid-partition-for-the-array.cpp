class Solution {
public:
    
    int solve(vector<int> &nums, int n, int type, int len, int curr, vector<vector<vector<int>>> &dp)
    {
        if(n < 0)
        {
            return len == 0;
        }
        
        if(type == 0 && len == 1 && curr != nums[n])
            return 0;
        if(type == 1 && len>=1 &&  curr != nums[n] )
            return 0;
        if(type == 2 && len>=1 && curr != nums[n]+1)
            return 0;
        
        if(dp[n][type][len] != -1)
            return dp[n][type][len];
          
        if(len == 0 )
            return dp[n][type][len] = solve(nums, n-1, 0, (len+1)%2, nums[n], dp) || solve(nums, n-1, 1, (len+1)%3, nums[n], dp) || solve(nums, n-1, 2, (len+1)%3, nums[n], dp);
        if(type == 2)
            return dp[n][type][len] = solve(nums, n-1, 2, (len+1)%3, nums[n], dp);
        if(type == 1)
            return dp[n][type][len] = solve(nums, n-1, 1, (len+1)%3, nums[n], dp);
        if(!type)
            return dp[n][type][len] = solve(nums, n-1, 0, (len+1)%2, nums[n], dp);
        
        return 0;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(4, vector<int>(4, -1)));
        return solve(nums, n-1, 3, 0, 0, dp);
    }
};