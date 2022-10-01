class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=0;i<numRows;i++)
        {
            vector<int> elem(i+1, 1);
            if(i<2)
                ans.push_back(elem);
            else
            {
                for(int j=1;j<i;j++)
                {
                    elem[j] = ans[i-1][j] + ans[i-1][j-1];
                }
                
                ans.push_back(elem);
            }
        }
        
        return ans;
    }
};