class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> mp;
        
        int n= nums.size();
        
        for(int i=0;i<n;i++)
        {
            int m = nums[i].size();
            for(int j=0;j<m;j++)
            {
                mp[nums[i][j]]++;
            }
        }
        
        vector<int> ans;
        for(auto it : mp)
        {
            if(it.second == n)
                ans.push_back(it.first);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};