class Solution {
public:
    void dfs(int curr, vector<int> adj[], vector<int> &vis)
    {
        vis[curr] = 1;
        for(auto it : adj[curr]){
            if(vis[it] != 1)
                dfs(it, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int m = isConnected[0].size();
        int ans = 0;
        
        vector<int> adj[n+1];
        vector<int> vis(n, 0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                 }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0){
                dfs(i, adj, vis);
                ans++;
            }
        }
        
        return ans;
    }
};