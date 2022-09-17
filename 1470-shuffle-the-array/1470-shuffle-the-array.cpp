class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0,j=n;
        vector<int> ans;
        
        for(;i<n;i++,j++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        
        return ans;
    }
};