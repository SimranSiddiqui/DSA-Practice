class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(m*n != r*c)
        {
            return mat;
        }
        
        vector<vector<int>> ans(r, vector<int>(c,-1));
        
        int newI =0;
        int newJ =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++,newJ++)
            {
                if(newJ >= c)
                {
                    newI++;
                    newJ =0;
                }
                
                ans[newI][newJ] = mat[i][j];
            }
        }
        
        return ans;
    }
};