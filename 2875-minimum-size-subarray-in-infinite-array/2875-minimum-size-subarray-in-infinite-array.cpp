class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long init = 0;
        long long sum = accumulate(nums.begin(), nums.end(), init);
        int ans = INT_MAX;
        int count = 0;
        
        if(target > sum)
        {
            count = target/sum; 
            target %= sum;
        }
        count *= n;
        if(target == 0)
            return count;
        
        int i, j;
        for(i=0,j=0;j<2*n;)
        {
            if(target == 0)
            {
                ans = min(ans, j-i);
                target -= nums[j%n];
                j++;
            }
            else if(target > 0)
            {
                target -= nums[j%n];
                j++;
            }
            else 
            {
                target += nums[i%n];
                i++;
            }
        }
        
        while(i < 2*n )
        {
            if(target == 0)
                ans = min(ans, j-i);
        
            target += nums[i%n];
            i++;
        }
        
        if(ans == INT_MAX)
            return -1;
        return ans+count;
    }
};