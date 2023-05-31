class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        int sum =0, ans=INT_MIN;
        for(int i=0,j=0;i<n;i++)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]]++;
                sum += nums[i];
                ans = max(ans, sum);
            }
            else
            {
                while(nums[i] != nums[j])
                {
                    mp.erase(nums[j]);
                    sum -= nums[j];
                    j++;
                }
                
                j++;
            }
        }
        
        return ans;
    }
};