class Solution {
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
public:
    int solve(vector<vector<int>> grid, int n, int m, int count, vector<vector<int>> &vis)
    {
        if(n<0 || m<0 || n >= grid.size() || m >= grid[0].size())
            return 0;
        if(vis[n][m] == 1 || grid[n][m] == -1)
            return 0;
        if(grid[n][m] == 2 && !count)
            return 1;
        
        vis[n][m] = 1;
        
        int ans = 0;
        for(int i=0;i<4;i++)
        {
            ans += solve(grid, n+dx[i], m+dy[i], count-1, vis);
        }
        vis[n][m] = 0;
        
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int row, col, count=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                    count++;
                if(grid[i][j] == 1)
                {
                    row = i;
                    col = j;
                }
            }
        }
        
        return solve(grid, row, col, count+1, vis);
    }
};