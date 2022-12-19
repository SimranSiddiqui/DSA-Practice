class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {   
        vector<int> adj[n];
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(auto it : adj[v])
            {
                if(vis[it] == 0)
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return vis[destination];
    }
};