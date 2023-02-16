class Solution {
    
    void func(vector<int>& nums, vector<vector<int>>& ans, int n, int i, vector<int>& curr)
    {
        if(i >= n)
        {
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(nums[i]);
        func(nums, ans, n, i+1, curr);
        curr.pop_back();
        func(nums, ans, n, i+1, curr);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        
        func(nums, ans, n, 0, curr);
        
        return ans;
    }
};