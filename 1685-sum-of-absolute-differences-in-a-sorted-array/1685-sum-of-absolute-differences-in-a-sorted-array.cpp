class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> left, right(n);
        
        int sum =0;
        for(int i=0;i<n;i++)
        {
            left.push_back(sum);
            sum += nums[i];
        }
        
        for(int i=n-1,sum =0;i>=0;i--)
        {
            right[i] = sum;
            sum += nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            int num1 = nums[i] * (i);
            int num2 = nums[i] * (n-i-1);
            
            int ans = abs(num1 - left[i]) + abs(num2 - right[i]);
            nums[i] = ans;
        }
        
        return nums;
    }
};