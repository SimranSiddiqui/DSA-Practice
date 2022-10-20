class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {0,0} ;
        int n= nums.size();
        int i=0,j=n-1,mid=0;
        int flag=0;
        
        while(i<=j)
        {
            mid = (i+j)/2;
            if(nums[mid]==target)
            {
                flag=1;
               break;   
            }
            else if(nums[mid]<target)
                i=mid+1;
            else 
                j=mid-1;
        }
        
        if(flag==0)
        {
          ans[0]=ans[1]=-1;
        }
        else
        {
          int l=mid, r=mid;
          while(l>0)
          {
              if(nums[l]==nums[l-1])
                  l--;
              else 
                  break;
          }
            ans[0]=l;
            
            while(r<n-1)
          {
              if(nums[r]==nums[r+1])
                  r++;
              else 
                  break;
          }
          ans[1]=r;
        }
        return ans;
    }
};