class Solution {
    
    int func(vector<int>& nums, int i, int base, vector<int>& dp)
    {
        if(i == base)
            return nums[base];
        if(i < base)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int p = nums[i] + func(nums, i-2, base, dp);
        int np = func(nums, i-1, base, dp);
        
        return dp[i] =  max(p, np);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        vector<int> dp(n, -1);
        int last = func(nums, n-1, 1, dp);
        fill(dp.begin(), dp.end(), -1);
        int first = func(nums, n-2, 0, dp);
        
        return max(last, first);
    }
};