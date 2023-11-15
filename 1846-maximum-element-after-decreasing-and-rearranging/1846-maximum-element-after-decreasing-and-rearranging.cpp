class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int ans = 1;
        arr[0] = 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i] - arr[i-1] <= 1)
                ans = arr[i];
            else
            {
                ans = arr[i-1] + 1;
                arr[i] = ans;
            }
        }
        
        return ans;
    }
};