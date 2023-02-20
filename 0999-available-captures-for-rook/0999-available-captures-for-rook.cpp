class Solution {
    
    void dfs(vector<vector<char>>& board,int r, int c, int &ans)
    {
        
        if(r<0 || r>=8 || c<0 || c>=8 || board[r][c] == 'B')
        {
            return;
        }
        
        if(board[r][c] == 'p')
        {
            ans++;
            return;
        }
        
    
        dfs(board, r-1, c, ans);
        dfs(board, r+1, c, ans);
        dfs(board, r, c+1, ans);
        dfs(board, r, c-1, ans);
    }
    
    
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans =0;
        int r, c;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j] == 'R')
                {
                    r = i;
                    c = j;
                }
            }
        }
        
        int k = r;
        while(k>=0)
        {
            if(board[k][c] == 'p')
            {
                ans++;
                break;
            }
            if(board[k][c] == 'B')
                break;
            
            k--;
        }
        k = c;
        while(k>=0)
        {
            if(board[r][k] == 'p')
            {
                ans++;
                break;
            }
            if(board[r][k] == 'B')
                break;
            
            k--;
        }
        k = r;
        while(k<8)
        {
            if(board[k][c] == 'p')
            {
                ans++;
                break;
            }
            if(board[k][c] == 'B')
                break;
            
            k++;
        }
        k = c;
        while(k<8)
        {
            if(board[r][k] == 'p')
            {
                ans++;
                break;
            }
            if(board[r][k] == 'B')
                break;
            
            k++;
        }
        
        return ans;
    }
};