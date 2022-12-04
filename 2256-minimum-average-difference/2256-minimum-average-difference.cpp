class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long> leftSum, rightSum;
        
         long sum =0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            long avg = sum/(i+1);
            leftSum.push_back(avg);
        }
        
      
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i == n-1)
                rightSum.push_back(0);
            else
            {
                  long avg = sum/(n-i-1);
                 rightSum.push_back(avg); 
            }
          
            sum += nums[i];
        }
        reverse(rightSum.begin(), rightSum.end());
        
        long ans = INT_MAX;
        int index =0;
        
        for(int i=0;i<n;i++)
        {
                if(ans > abs(leftSum[i]-rightSum[i]))
                    index = i;
                ans = min(ans, abs(leftSum[i]-rightSum[i])); 
        }
        
        return index;
            
    }
};