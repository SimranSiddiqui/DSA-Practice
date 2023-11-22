class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int, priority_queue<pair<int, int>>> mp;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push(make_pair(i, nums[i][j]));
            }
        }
        
        for(auto it: mp)
        {
            while(!(it.second).empty())
            {
                ans.push_back((it.second).top().second);
                (it.second).pop();
            }
        }
        return ans;
    }
};