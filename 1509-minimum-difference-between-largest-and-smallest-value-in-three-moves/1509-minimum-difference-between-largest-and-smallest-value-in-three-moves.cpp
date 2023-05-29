class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = INT_MIN;
        
        ans = min(nums[n-4] - nums[0], nums[n-1] - nums[3]);
        ans = min(ans, nums[n-3]-nums[1]);
        ans = min(nums[n-2] - nums[2], ans);
        
        return ans;
    }
};