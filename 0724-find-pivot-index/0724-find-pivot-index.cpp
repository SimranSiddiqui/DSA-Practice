class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        
        int sum =0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
               leftSum[i] = 0;
                sum += nums[i];
            }
            else
            {
                leftSum[i] = sum;
                sum += nums[i];
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                sum = 0;
                rightSum[i] = 0;
                sum += nums[i];
            }
            else
            {
                rightSum[i] = sum;
                sum += nums[i];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(leftSum[i] == rightSum[i])
                return i;
        }
        return -1;
    }
};