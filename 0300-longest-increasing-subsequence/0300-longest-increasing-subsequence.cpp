class Solution {
    int solve(int n, vector<int> &nums, int last, vector<vector<int>> &dp)
    {
        if(n<0)
            return 0;
        if(dp[n][last] != -1)
            return dp[n][last];
        
        int bigg = 0;
        if(last == nums.size())
            bigg = INT_MAX;
        else
            bigg = nums[last];
        
        if(nums[n] < bigg)
            return dp[n][last] = max(solve(n-1, nums, n, dp)+1, solve(n-1, nums, last, dp));
        else
            return dp[n][last] = solve(n-1, nums, last, dp);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int last = n;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(n-1, nums, last, dp);
    }
};