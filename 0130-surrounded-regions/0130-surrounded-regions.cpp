class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O')
                {
                    if(vis[i][j] != 1)
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            
            vis[row][col] = 1;
            
            if(row-1>=0 && vis[row-1][col] == 0 && board[row-1][col] == 'O')
                q.push({row-1, col});
            if(col-1>=0 && vis[row][col-1] == 0 && board[row][col-1] == 'O')
                q.push({row, col-1});
            if(row+1<n && vis[row+1][col] == 0 && board[row+1][col] == 'O')
                q.push({row+1, col});
            if(col+1<m && vis[row][col+1] == 0 && board[row][col+1] == 'O')
                q.push({row, col+1});
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};