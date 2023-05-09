class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        int up = 0, down = n-1, left = 0, right = m-1;
        while(left<=right && up <= down)
        {
            for(int i=left;i<=right && up<=down;i++)
            {
                ans.push_back(matrix[up][i]);
            }
            up++;
            for(int i=up;i<=down && left<=right;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right;i>=left && up<=down;i--)
            {
                ans.push_back(matrix[down][i]);
            }
            down--;
            for(int i=down;i>=up && left<=right;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return ans;
    }
};