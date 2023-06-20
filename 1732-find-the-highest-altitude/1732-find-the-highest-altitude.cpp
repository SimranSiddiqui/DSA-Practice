class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum =0;
        int n = gain.size();
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            sum += gain[i];
            maxi = max(sum, maxi);
        }
        
        if(maxi<0)
            return 0;
        
            return maxi;
    }
};