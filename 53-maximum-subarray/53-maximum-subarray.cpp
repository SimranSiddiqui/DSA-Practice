class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currentSum = nums[0];
        int ans = nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(currentSum >= 0)
            {
                currentSum += nums[i];
            }
            else
            {
                currentSum = nums[i];
            }
            ans = max(currentSum, ans);
        }
        return ans;
    }
};