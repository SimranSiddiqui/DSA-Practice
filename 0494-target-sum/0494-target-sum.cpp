class Solution {
    
    int func(vector<int>& nums, int i, int target)
    {
        if(i < 0 && target==0)
            return 1;
        if(i < 0)
            return 0;
        
        int plus = func(nums, i-1, target-nums[i]);
        int minus = func(nums, i-1, target+nums[i]);
        
        return plus+minus;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        
        return func(nums, n-1, target);
    }
};