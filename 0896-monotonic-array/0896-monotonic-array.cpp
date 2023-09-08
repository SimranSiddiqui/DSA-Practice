class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int inc=0, dec=0, eq=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == nums[i+1])
                eq++;
            else if(nums[i] > nums[i+1])
                dec++;
            else
                inc++;
                
        }
        
        return inc+eq==n-1 || dec+eq==n-1;
    }
};