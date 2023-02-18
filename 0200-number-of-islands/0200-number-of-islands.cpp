class Solution {

    void bfs(vector<vector<char>>& grid, int n, int m, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        grid[i][j] = '0';

        while(!q.empty())
        {
            int size = q.size();
            for(int x = 0;x<size;x++)
            {
                pair<int, int> node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                grid[r][c] = '0';


                if(r+1 < n && grid[r+1][c] == '1')
                {
                    grid[r+1][c] = '0';
                    q.push(make_pair(r+1, c));
                }
                if(c+1 < m  && grid[r][c+1] == '1')
                {
                    grid[r][c+1] = '0';
                    q.push(make_pair(r, c+1));
                }
                if(r-1 >= 0 && grid[r-1][c] == '1')
                {
                    grid[r-1][c] = '0';
                    q.push(make_pair(r-1, c));
                }
                if(c-1  >= 0 && grid[r][c-1] == '1')
                {
                    grid[r][c-1] = '0';
                    q.push(make_pair(r, c-1));
                }

            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    bfs(grid, n, m, i, j);
                }
            }
        }

        return ans;
    }
};