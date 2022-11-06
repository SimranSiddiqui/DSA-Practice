class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        long ans = INT_MIN;
        
        long sum =0;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
            sum += nums[i];
        }
        
        for(int i=0,j=k;j<n;j++,i++)
        {
            if(mp.size() == k)
            {
                ans = max(ans, sum);
            }
            
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
            
            mp[nums[j]]++;
            
            sum += nums[j] - nums[i];
        }
        
        if(mp.size() == k)
            ans = max(ans, sum);
        
        if(ans != INT_MIN)
        return ans;
        else
            return 0;
    }
};