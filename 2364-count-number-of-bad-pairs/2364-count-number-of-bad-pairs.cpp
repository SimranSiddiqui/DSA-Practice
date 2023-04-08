class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            nums[i] -= i;
        }
        
        unordered_map<int, int> mp;
        
        long long count =0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                count += mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        
        long long total = (n-1)*(n)/2;
        return total - count;
    }
};