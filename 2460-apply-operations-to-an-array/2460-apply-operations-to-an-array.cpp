class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        
        int i =0, j = 0;
       
        while(i<n && j<n)
        {
            while(i<n && nums[i]!=0 )
            {
                i++;
            }
            j = i+1;
            while(j<n && nums[j] == 0)
            {
                j++;
            }
            
            if(j<n && i<n)
            nums[i] = nums[j];
            if(j<n)
            nums[j] = 0;
            i++;
        }
        
        return nums;
    }
};