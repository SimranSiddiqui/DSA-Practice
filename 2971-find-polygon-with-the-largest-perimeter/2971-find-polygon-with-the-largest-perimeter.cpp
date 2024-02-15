class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++)
        {
            pre.push_back(sum);
            sum += nums[i];
        }
        
        for(int i=n-1;i>=2;i--)
        {
            if(nums[i] < pre[i])
            {
                sum = nums[i]+pre[i];
                return sum;
            }
        }
        
        return -1;
    }
};