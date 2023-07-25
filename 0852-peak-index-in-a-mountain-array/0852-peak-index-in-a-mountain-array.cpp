class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int i = 1, j = n-2;
        while(i <= j)
        {
            int mid  = i + (j - i)/2;
            
            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])
            {
                return mid;
            }
            else if(arr[mid-1] < arr[mid] && arr[mid+1] > arr[mid])
            {
                i = mid+1;
            }
            else
            {
                j = mid-1;
            }
        }
        
        return 0;
    }
};