class Solution {
public:
    
    vector<int> delR = {0, 0, 1, -1};
    vector<int> delC = {1, -1, 0, 0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            ans[row][col] = dist;
            
            for(int i=0;i<4;i++)
            {
                int nR = row + delR[i];
                int nC = col + delC[i];
                if(nR>=0 && nR<n && nC>=0 && nC<m && vis[nR][nC] == 0)
                {
                    q.push({{nR, nC}, dist+1});
                    vis[nR][nC] = 1;
                }
            }
        }
        
        return ans;
    }
};