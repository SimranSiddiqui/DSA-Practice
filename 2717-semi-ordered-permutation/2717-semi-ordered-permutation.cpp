class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        
        if(nums[0] == 1 && nums[n-1] == n)
            return 0;
        
        int i =0;
        int ind1=0, indn =0;
        while(i<n)
        {
            if(nums[i] == 1)
                ind1 = i;
            if(nums[i] == n)
                indn = i;
            
            i++;
        }
        
        if(indn < ind1)
            ans--;
        
        ans += ind1 + n-indn-1;
        
        return ans;
    }
};