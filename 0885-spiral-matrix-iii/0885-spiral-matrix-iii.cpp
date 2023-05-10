class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int rStart, int cStart) {
        vector<vector<int>> mat(n, vector<int>(m ,0));
        vector<vector<int>> ans;
        
        int top = rStart, bottom = rStart, left = cStart, right = cStart;
        while(ans.size() < n*m)
        {
            for(int i=left;i<=right+1 && ans.size() < n*m;i++)
            {
                if(i<m && i>=0 && top >=0 && top < n && mat[top][i] == 0)
                {
                    vector<int> x = {top, i};
                    ans.push_back(x);
                    mat[top][i] = 1;
                }
            }
            right++;
            
            for(int i=top;i<=bottom+1 && ans.size() < n*m;i++)
            {
                if(i<n && i>=0 && right >=0 && right < m && mat[i][right] == 0)
                {
                    vector<int> x = {i, right};
                    ans.push_back(x);
                    mat[i][right] = 1;
                }
            }
            bottom++;
            
            for(int i=right;i>=left-1 && ans.size() < n*m;i--)
            {
                if(i<m && i>=0 && bottom >=0 && bottom < n && mat[bottom][i] == 0)
                {
                    vector<int> x = {bottom, i};
                    ans.push_back(x);
                    mat[bottom][i] = 1;
                }
            }
            left--;
            
            for(int i=bottom;i>=top-1 && ans.size() < n*m;i--)
            {
                if(i<n && i>=0 && left >=0 && left < m && mat[i][left] == 0)
                {
                    vector<int> x = {i, left};
                    ans.push_back(x);
                    mat[i][left] = 1;
                }
            }
            top--;
        }
        
        return ans;
    }
};