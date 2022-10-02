class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count =0;
        int n=nums.size();
        bool zero = false;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
                count++;
            if(nums[i]==0)
            {
                zero = true;
            }
        }
        
        if(zero)
            return 0;
        else if(count%2 ==0)
            return 1;
        else
            return -1;
        
    }
};