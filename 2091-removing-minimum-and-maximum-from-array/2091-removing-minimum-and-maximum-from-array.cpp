class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int indMin=0, indMax=0;
        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                indMax = i+1;
            }
            if(nums[i] < mini)
            {
                mini = nums[i];
                indMin = i+1;
            }
        }
        
        if(indMin < indMax)
            return min(indMax, min(indMin+n-indMax+1, n-indMin+1));
        
            return min(indMin, min(indMax+n-indMin+1, n-indMax+1));
    }
};