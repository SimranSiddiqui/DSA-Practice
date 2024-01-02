class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int maxFreq = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            maxFreq = max(maxFreq, mp[nums[i]]);
        }
        
        vector<vector<int>> ans(maxFreq, vector<int>());
        
        for(auto it: mp)
        {
            int count = it.second;
            for(int i=0;i<count;i++)
            {
                ans[i].push_back(it.first);
            }
        }
        
        return ans;
    }
};