class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
       int n= nums.size();
        
        pair<int,int> pr;
        pr = {INT_MAX, INT_MIN};
        
        for(int i=0;i<n;i++)
        {
            if(abs(nums[i]) < pr.first)
            {
                pr = {abs(nums[i]), nums[i]};
            }
            else if(abs(nums[i]) == pr.first)
            {
                if(nums[i] > pr.second)
                {
                    pr.second = nums[i];
                }
            }
        }
        
        return pr.second;
        
        
    }
};