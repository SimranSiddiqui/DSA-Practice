class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> mp;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(mp.find(board[i][j]) != mp.end())
                    return false;
                if(board[i][j] - '1' > 9)
                    return false;
                if(board[i][j] == '.')
                    continue;
                mp[board[i][j]]++;
            }
            
            mp.clear();
        }
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(mp.find(board[j][i]) != mp.end())
                    return false;
                if(board[j][i] - '1' > 9)
                    return false;
                if(board[j][i] == '.')
                    continue;
                mp[board[j][i]]++;
            }
  
            mp.clear();
        }
        
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                int r = i, c = j;
                
                while(r < i+3)
                {
                    c = j;
                    while(c < j+3)
                    {
                        
                        //cout << board[r][c] << " ";
                        
                        if(mp.find(board[r][c]) != mp.end())
                             return false;
                        if(board[r][c] - '0' > 9)
                              return false;
                        if(board[r][c] != '.')
                         mp[board[r][c]]++;
                        
                        c++;
                    }
                    
                    //cout << endl;
                    r++;
                }
                
                 mp.clear();
            }
        }
        
        return true;
    }
};