class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_map<int, int>> mp(n);
        
        for(auto it: roads)
        {
            int u = it[0];
            int v = it[1];
            
            mp[u][v]++;
            mp[v][u]++;
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = mp[i].size() + mp[j].size();
                
                if(mp[i].find(j) != mp[i].end())
                    sum--;
                
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};