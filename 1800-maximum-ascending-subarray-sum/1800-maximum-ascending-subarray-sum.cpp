class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int ans = sum;
        
        for(int i=1;i<n;i++)
        {
            while(i<n && nums[i] > nums[i-1])
            {
                sum += nums[i];
                ans = max(ans, sum);
                i++;
            }
            
            if(i<n)
                sum = nums[i];
        }
        
        return ans;
    }
};