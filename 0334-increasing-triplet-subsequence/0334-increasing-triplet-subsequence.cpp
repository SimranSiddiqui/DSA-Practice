class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MAX;
        int max2 = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] <= max1)
                max1 = nums[i];
            else if(nums[i] <= max2)
                max2 = nums[i];
            else
                return true;
        }
        
        return false;
    }
};