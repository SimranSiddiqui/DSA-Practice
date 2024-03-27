class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int pro = 1;
        int ans = 0;
        
        for(int i=0,j=0;j<n;)
        {
            if(nums[j] >= k)
            {
                i = ++j;
                pro = 1;
                continue;
            }
            pro *= nums[j];
            
            while(pro >= k)
            {
                pro /= nums[i];
                i++;
            }
            cout << i << " " << j << endl;
            ans += j-i+1;
            j++;
        }
        
        return ans;
    }
};