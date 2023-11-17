class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i=0, j=n-1;
        int ans = INT_MIN;
        while(i<n)
        {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }
        
        return ans;
    }
};