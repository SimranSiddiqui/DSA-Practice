class Solution {
public:
    
    vector<int> dRow = {-1, 0, 1, 0};
    vector<int> dCol = {0, 1, 0, -1};

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i == 0 || j==0 || i == n-1 || j == m-1) && grid[i][j] == 1 && vis[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            
            int r = curr.first, c = curr.second;
            vis[r][c] = 1;
            
            for(int i=0;i<4;i++)
            {
                if(r+dRow[i] >= 0 && r+dRow[i] < n && c + dCol[i] >= 0 && c + dCol[i] < m && vis[r+dRow[i]][c + dCol[i]] == 0 && grid[r+dRow[i]][c + dCol[i]] == 1)
                {
                    q.push({r+dRow[i], c + dCol[i]});
                    vis[r+dRow[i]][c + dCol[i]] = 1;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }
        
        return count;
    }
};