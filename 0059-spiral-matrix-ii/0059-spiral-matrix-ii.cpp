class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int top =0, left =0;
        int bottom =n-1, right =n-1;
        int x = 1;
        
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right && top<=bottom;i++)
            {
                ans[top][i] = x;
                x++;
            }
            top++;
            
            for(int i=top;i<=bottom && left<=right;i++)
            {
                ans[i][right] = x;
                x++;
            }
            right--;
            
            for(int i=right;i>=left && top<=bottom;i--)
            {
                ans[bottom][i] = x;
                x++;
            }
            bottom--;
            
            for(int i=bottom;i>=top && left<=right;i--)
            {
                ans[i][left] = x;
                x++;
            }
            left++;
            
        }
        
        return ans;
    }
};