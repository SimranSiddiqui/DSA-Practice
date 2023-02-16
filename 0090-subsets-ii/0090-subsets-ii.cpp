class Solution {
    void func(vector<int>& nums, vector<vector<int>>& ans, int n, int ind, vector<int>& curr)
    {
        for(int i =ind;i<n;i++)
        {
            if(i==ind || nums[i] != nums[i-1])
            {
                curr.push_back(nums[i]);
                func(nums, ans, n, i+1, curr);
                curr.pop_back();
            }
        }
        
        ans.push_back(curr);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        
        func(nums, ans, n, 0, curr);
        return ans;
    }
};