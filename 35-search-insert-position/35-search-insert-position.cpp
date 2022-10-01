class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans;
        
        if(target < nums[0])
            return 0;
        else if(target > nums[n-1])
            return n;
        else
        {
            int i = 0;
            int j = n-1;
        
            while(i<=j)
            {
                int mid = j - (j-i)/2;
                if(nums[mid] == target)
                {
                 ans = mid;
                    break;
                }
                else if(nums[mid]>target && nums[mid-1]<target)
                   {
                      ans = mid;
                    break;
                   }
                else if(nums[mid] > target)
                    j = mid-1;
                else 
                    i = mid+1;
            }
        }
        
        return ans;
    }
};