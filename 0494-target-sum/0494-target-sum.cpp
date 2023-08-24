class Solution {
public:
    int solve(vector<int> &nums, int n, int target)
    {
        if(n < 0)
            return target == 0;
        
        return  solve(nums, n-1, target-nums[n]) + solve(nums, n-1, target+nums[n]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, n-1, target);
    }
};