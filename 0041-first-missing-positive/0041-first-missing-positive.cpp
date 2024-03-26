class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int count = 1;
        for(int i=0;i<n;i++)
        {
            if(nums[i] <= 0)
                continue;
            else if(nums[i] > count)
                break;
            else if(i>0 && nums[i] == nums[i-1])
                continue;
            else
                count++;
        }
        
        return count;
    }
};