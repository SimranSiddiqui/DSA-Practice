class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ret = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                int j = abs(i-start);
                if(j<ret)
                {
                    ret = j;
                }
                    
            }
        }
        
        return ret;
        
    }
};