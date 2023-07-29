class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, ans = INT_MIN;
        
        for(int i=0,j=0;j<n;)
        {
            if(count < k)
            {
                if(nums[j] == 0)
                {
                    count++;
                }
                
                j++;
                ans = max(ans, j-i);
            }
            else if(count == k)
            {
                if(nums[j] == 1)
                {
                    j++;
                    ans = max(ans, j-i);
                }
                else
                {
                    while(nums[i] != 0)
                        i++;
                    
                    if(nums[i] == 0)
                    {
                        count--;
                        i++;
                    }
                }
            }
        }
        
        return ans;
    }
};