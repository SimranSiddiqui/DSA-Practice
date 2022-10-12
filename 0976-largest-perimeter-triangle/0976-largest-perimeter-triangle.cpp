class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        
        int i=0,j=1,k=2;
        int maxPeri = 0;
        while(k<n)
        {
            if(nums[i]+nums[j]>nums[k] && nums[k]+nums[j]>nums[i] && nums[i]+nums[k]>nums[j])
            {
                maxPeri = (nums[i]+nums[j]+nums[k]);
                break;
            }
            else
            {
                i++;
                j++;
                k++;
            }
        }
        return maxPeri;
    }
};