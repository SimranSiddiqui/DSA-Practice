class Solution {
public:
    int averageValue(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int sum =0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0 && nums[i]%3==0)
            {
                sum += nums[i];
                count++;
            }
        }
        
        if(count ==0)
            return 0;
        return sum/count;
    }
};