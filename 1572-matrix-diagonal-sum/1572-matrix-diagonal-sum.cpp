class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        
        int sum = 0;
        for(int i=0, j=0; i<n&&j<n; i++,j++)
        {
            sum += mat[i][j];
            mat[i][j] = 0;
        }
        
        for(int i=0,j=n-1;i<n && j>=0; i++,j--)
        {
            sum += mat[i][j];
            mat[i][j] = 0;
        }
        
        return sum;
    }
};