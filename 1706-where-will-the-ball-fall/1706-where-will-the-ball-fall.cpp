class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int j=0;j<grid[0].size();j++)
        {
            int currentPosition=j;
            int nextPosition = -1;
            for(int i = 0; i<grid.size();i++)
            {
                nextPosition = currentPosition + grid[i][currentPosition];
                if(nextPosition<0 || nextPosition>=grid[0].size() || grid[i][currentPosition]!=grid[i][nextPosition])
                {
                    currentPosition = -1;
                    break;
                }
                currentPosition = nextPosition;
            }
            ans.push_back(currentPosition);
        }
        
        return ans;
        
    }
};