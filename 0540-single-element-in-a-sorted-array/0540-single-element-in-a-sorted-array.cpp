class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l = 0, r=n-1, mid;
        while(l<r)
        {
           mid=(l+r)/2;
         
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid-1])
                r=mid-2;
                else if(nums[mid]==nums[mid+1])
                l=mid+2;
                else
                return nums[mid];
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return nums[r];
    }
};