class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int curr =1, ans = 0; 
        
        if(n == 0)
            return 0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
            {
                continue;
            }
            if(nums[i] == nums[i-1] + 1)
            {
                curr++;
                ans = max(curr, ans);
            }
            else
            {
                curr =1;
            }
        }
        
        ans = max(ans, curr);
        return ans;
    }
};