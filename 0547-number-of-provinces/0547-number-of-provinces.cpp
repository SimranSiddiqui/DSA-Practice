class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, int i, vector<int>& visited){
        int n = isConnected.size();

        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp]=1;
            for(int j=0;j<n;j++){
                if(isConnected[temp][j]==1 && visited[j]==0) q.push(j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans++;
                bfs(isConnected,i,visited);
            }
        }
        return ans;
    }
};