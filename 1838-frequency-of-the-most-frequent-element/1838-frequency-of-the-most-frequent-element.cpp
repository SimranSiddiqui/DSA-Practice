class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        
        for(int i=n-1;i>=0;)
        {
            int freq = 0;
            int num = nums[i];
            while(i>=0 && nums[i] == num)
            {
                freq++;
                i--;
            }
            
            int x = k;
            int j = i;
            while(j>=0 && x > 0)
            {
                if(num - nums[j] <= x)
                {
                    freq++;
                    x -= num - nums[j];
                    j--;
                }
                else
                {
                    break;
                }
            }
            
            ans = max(ans, freq);
        }
        
        return ans;
    }
};