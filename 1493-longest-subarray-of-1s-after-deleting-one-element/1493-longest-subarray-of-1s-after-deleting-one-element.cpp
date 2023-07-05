class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left, right(n, 0);
        
        int count =0, ans = 0;
        for(int i=0;i<n;i++)
        {
            left.push_back(count);
            if(nums[i] == 0)
            {
                count =0;
            }
            else
                count++;
        }
        
        count =0;
        for(int i=n-1;i>=0;i--)
        {
            right[i] = count;
            if(nums[i] == 0)
            {
                count =0;
            }
            else
                count++;
        }
        
        for(int i=0;i<n;i++)
        {
            ans = max(ans, left[i]+right[i]);
        }
        
        return ans;
    }
};