class Solution {
    
    int findPivot(vector<int> nums, int i, int j)
    {
        while(i<j)
        {
            if(nums[i] > nums[i+1])
            {
                return i;
            }
            i++;
        }
        
        return -1;
    }
    
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        int index = findPivot(nums, 0, n-1);
        
        if(index == -1)
            return true;
        
        int i = index;
        int j = index+1;
        
        for(;i>0;i--)
        {
            if(nums[i] < nums[i-1])
            {
                return false;
            }
        }
        
         for(;j<n-1;j++)
        {
            if(nums[j] > nums[j+1])
            {
                return false;
            }
        }
        
        if(nums[j] > nums[i])
            return false;
        
        return true;
    }
};