class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = INT_MIN;
        
        for(int i=0;i<left.size();i++)
        {
            maxi = max(maxi, left[i]);
        }
        
        for(int i=0;i<right.size();i++)
        {
            maxi = max(maxi, n - right[i]);
        }
        
        return maxi;
    }
};