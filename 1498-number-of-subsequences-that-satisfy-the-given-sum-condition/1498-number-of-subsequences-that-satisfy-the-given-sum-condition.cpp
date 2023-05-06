class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        long long mod = 1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> power(n , 1);
        int pow = 1;
        for(int i=1;i<n;i++)
        {
            pow = (pow%mod * 2%mod)%mod;
            power[i] = pow;
        }
        
        int left = 0, right = n-1;
        long long ans = 0;
        while(left <= right)
        {
            if(nums[left]+nums[right] > target)
            {
                right--;
            }
            else
            {
                ans =  (ans%mod + power[right - left]%mod)%mod;
                left++;
            }
        }
        
        return ans;
    }
};