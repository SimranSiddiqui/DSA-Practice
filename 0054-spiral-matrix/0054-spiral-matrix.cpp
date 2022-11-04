class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        
        int top = 0;
        int bottom = m-1;
        int left =0;
        int right = n-1;
        
        while(left<=right && top<=bottom)
        {
            for(int i =left;i<=right && top<=bottom;i++)
            {
                int x = matrix[top][i];
                ans.push_back(x);
            }
            top++;
            
            for(int i=top;i<=bottom && left<=right;i++)
            {
                int x = matrix[i][right];
                ans.push_back(x);
            }
            right--;
            
            for(int i=right;i>=left && top<=bottom;i--)
            {
                int x = matrix[bottom][i];
                ans.push_back(x);   
            }
            bottom--;
            
            for(int i=bottom;i>=top && left<=right;i--)
            {
                int x = matrix[i][left];
                ans.push_back(x);   
            }
            left++;  
        }
        
        return ans;
    }
};