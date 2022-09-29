class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[nums[n-1]]++;
        int count =0;
        
        for(int i=n-2;i>=0;i--)
        {
            if(mp.find(nums[i]+k) != mp.end())
                count += mp[nums[i]+k];
            if(mp.find(nums[i]-k) != mp.end())
                count += mp[nums[i]-k];
            
            mp[nums[i]]++;
        }
        
        return count;
    }
};