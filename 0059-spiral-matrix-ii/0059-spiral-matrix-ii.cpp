class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int top = 0, bottom =n-1, left = 0, right = n-1;
        int num = 1;
        while(top <= bottom && left <= right)
        {
            for(int i=left;i<=right && num<=n*n;i++)
            {
                ans[top][i] = num;
                num++;
            }
            top++;
            for(int i=top;i<=bottom&& num<=n*n;i++)
            {
                ans[i][right] = num;
                num++;
            }
            right--;
            for(int i=right;i>=left&& num<=n*n;i--)
            {
                ans[bottom][i] = num;
                num++;
            }
            bottom--;
            for(int i=bottom;i>=top&& num<=n*n;i--)
            {
                ans[i][left] = num;
                num++;
            }
            left++;
        }
        
        return ans;
    }
};