class Solution {
public:
    bool isvalid(vector<int>&pos1, vector<int>&pos2)
    {
        if (pos1[0] == pos2[0]) return true;
        if (pos1[1] == pos2[1]) return true;
        return false;
    }
    void dfs(vector<vector<int>>& stones,int idx,vector<bool> &vis,int n){
        vis[idx]=true;
        for(int i=0; i<n; i++){
            if(vis[i]) 
                continue;
            if(isvalid(stones[i],stones[idx]))
                dfs(stones,i,vis,n);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n,false);
        int c=0;
        for(int i=0; i<n; i++){
            if(vis[i])
                continue;
            dfs(stones,i,vis,n);
            c++;
        }
        return (n-c);
    }
};