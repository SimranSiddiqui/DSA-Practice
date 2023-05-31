class Solution {
public:
    bool check(vector<int>& nums) {
        int diff = 0;
        int n = nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] < nums[i-1])
                diff++;
        }
        
        if(nums[n-1] > nums[0])
            diff++;
        
        if(diff > 1)
            return false;
        return true;
    }
};