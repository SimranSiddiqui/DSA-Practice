class Solution {
    
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans =0;
        
        for(int i=0;i<n;i++)
        {
            if(boxTypes[i][0] >= truckSize)
            {
                ans += truckSize*boxTypes[i][1];
                break;
            }
            else
            {
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } 
        }
        
        return ans;
    }
};