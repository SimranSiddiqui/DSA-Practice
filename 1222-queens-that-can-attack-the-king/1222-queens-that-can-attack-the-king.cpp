class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = 8;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        int m = queens.size();
        
        for(int i=0;i<m;i++)
        {
            int r = queens[i][0];
            int c = queens[i][1];
            
            grid[r][c] = 1;
        }
        
        vector<vector<int>> ans;
        int sCol = king[0];
        int sRow = king[1];
        
        int i = sCol, j=sRow;
        while(i >= 0)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            i--;
        }
        i = sCol, j=sRow;
        while(i < n)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            i++;
        }
        i = sCol, j=sRow;
        while(j >= 0)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            j--;
        }
        i = sCol, j=sRow;
        while(j < n)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            j++;
        }
        i = sCol, j=sRow;
        while(i>=0 && j >=0)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            j--;
            i--;
        }
        i = sCol, j=sRow;
        while(i<n && j >=0)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            j--;
            i++;
        }
        i = sCol, j=sRow;
        while(i<n && j<n)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            j++;
            i++;
        }
        i = sCol, j=sRow;
        while(i>=0 && j<n)
        {
            if(grid[i][j])
            {
                ans.push_back({i, j});
                break;
            }
            j++;
            i--;
        }
        
        return ans;
    }
};