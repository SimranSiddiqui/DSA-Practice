class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        
        int n = logs.size();
        unordered_map<int, unordered_set<int> > mp;
        for(int i=0;i<n;i++)
        {
            mp[logs[i][0]].insert(logs[i][1]);
        }
        
        for(auto it: mp)
            ans[it.second.size() - 1]++;
        
        return ans;
    }
};