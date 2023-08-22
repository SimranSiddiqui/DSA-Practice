class Solution {
public:
    
    bool solve(int n, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0)
            return 1;
        if(n<0 || sum<0)
            return false;
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        
        return dp[n][sum] = solve(n-1, nums, sum-nums[n], dp) || solve(n-1, nums, sum, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum1 =0, sum2=0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return solve(n-1, nums, sum/2, dp);
    }
};