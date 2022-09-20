class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int i=1;
        while(arr[i]>arr[i-1] && i<n)
        {
            i++;
        }
        
        return i-1;
    }
};