class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        if(n <= 2)
            return true;
        
        vector<int> p1 = coordinates[0], p2 = coordinates[1];
        for(int i=2;i<n;i++)
        {
            vector<int> p3 = coordinates[i];
            int val = p1[0]*(p2[1]-p3[1]) + p2[0]*(p3[1]-p1[1]) + p3[0]*(p1[1]-p2[1]);
            
            if(val)
                return false;
        }
        
        return true;
    }
};