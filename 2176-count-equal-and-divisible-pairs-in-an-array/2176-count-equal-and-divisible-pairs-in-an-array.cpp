class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int count =0;
        
        mp[nums[n-1]].push_back(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                for(int j=0;j<mp[nums[i]].size();j++)
                {
                    if((i*mp[nums[i]][j])%k == 0)
                        count++;
                }
            }
            mp[nums[i]].push_back(i);
        }
        
        return count;
    }
};