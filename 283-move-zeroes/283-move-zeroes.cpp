class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==0)
            {
                count++;
            }
            nums[i-count] = nums[i];
        }
        
        while(count)
        {
            nums[n-count] = 0;
            count--;
        }
    }
};