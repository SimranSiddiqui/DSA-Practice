class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        
        int i=0, j=0;
        int sum =0;
        
        while(j < n)
        {
            if(sum < target)
            {
                sum += nums[j];
                j++;
            }
            else if(sum > target)
            {
                while(sum > target)
                {
                    ans = min(ans, j-i);
                    sum -= nums[i];
                    i++;
                }
            }
            else
            {
                ans = min(ans, j-i);
                sum += nums[j];
                j++;
            }
        }
        
        if(sum > target)
            {
                while(sum > target)
                {
                    ans = min(ans, j-i);
                    sum -= nums[i];
                    i++;
                }
            }
         if(sum == target)
                    ans = min(ans, j-i);
        
        if(ans == INT_MAX)
            ans = 0;
        return ans;
    }
};