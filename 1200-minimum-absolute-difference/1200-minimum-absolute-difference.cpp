class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        int n = arr.size();
        
        for(int i=1;i<n;i++)
        {
            diff = min(abs(arr[i]-arr[i-1]), diff);
        }
        
        vector<vector<int>> ans;
        
        for(int i=1;i<n;i++)
        {
            if(abs(arr[i]-arr[i-1]) == diff)
            {
                vector<int> x = {arr[i-1], arr[i]};
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};