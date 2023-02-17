class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int count =0;
        
        for(int i=0;i<n;i++)
        {
          mp[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(k == 0)
            {
                if(mp[nums[i]] > 1)
                    count++;
                mp.erase(nums[i]);
                continue;
            }
            if(mp.find(nums[i]) != mp.end() &&  mp.find(nums[i] - k) != mp.end())
                count++;
            if(mp.find(nums[i]) != mp.end() && mp.find(nums[i]+k) != mp.end())
                count++;
            mp.erase(nums[i]);
        }
        
        return count;
    }
};