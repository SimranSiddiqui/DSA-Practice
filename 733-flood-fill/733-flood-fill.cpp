class Solution {
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int n = image.size();
       int m = image[0].size();
        
      vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<int,int>> q;
        q.push(make_pair(sr, sc));
        vis[sr][sc] = 1;
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(i-1 >= 0 && image[i-1][j]==image[sr][sc])
            {
                if(vis[i-1][j] == 0)
                {
                  image[i-1][j] = color;
                  q.push(make_pair(i-1,j));
                  vis[i-1][j] = 1;   
                }
            }
            if(i+1 < n && image[i+1][j] == image[sr][sc])
            {
               if(vis[i+1][j] == 0)
                {
                  image[i+1][j] = color;
                  q.push(make_pair(i+1,j));
                  vis[i+1][j] = 1;   
                } 
            }
            if(j-1 >= 0 && image[i][j-1] == image[sr][sc])
            {
                 if(vis[i][j-1] == 0)
                {
                  image[i][j-1] = color;
                  q.push(make_pair(i,j-1));
                  vis[i][j-1] = 1;   
                } 
            }
            if(j+1 >= 0 && image[i][j+1] == image[sr][sc])
            {
                 if(vis[i][j+1] == 0)
                {
                  image[i][j+1] = color;
                  q.push(make_pair(i,j+1));
                  vis[i][j+1] = 1;   
                } 
            }
            
        }
        
         image[sr][sc] = color;
        return image;
        
    }
};