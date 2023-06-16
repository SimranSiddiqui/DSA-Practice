class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        int level = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    level = -1;
                   q.push(make_pair(i, j)); 
                   grid[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            level++;
            int size = q.size();

            for(int x=0;x<size;x++)
            {
            pair<int, int> curr = q.front();
            q.pop();
            
            int i = curr.first;
            int j = curr.second;
            
            if(i-1>=0 && grid[i-1][j] == 1)
            {
                q.push(make_pair(i-1, j));
                grid[i-1][j] = 0;
            }
            if(j-1>=0 && grid[i][j-1] == 1)
            {
                q.push(make_pair(i, j-1));
                grid[i][j-1] = 0;
            }
            if(i+1<n && grid[i+1][j] == 1)
            {
                q.push(make_pair(i+1, j));
                grid[i+1][j] = 0;
            }
            if(j+1<m && grid[i][j+1] == 1)
            {
                q.push(make_pair(i, j+1));
                grid[i][j+1] = 0;
            }
        }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return level;
    }
};