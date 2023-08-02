class Solution {
    
    void solve(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int n, unordered_map<int, int> &mp)
    {
        if(curr.size() == n)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]]++;
                curr.push_back(nums[i]);
                
                solve(nums, curr, ans, n, mp);
                
                mp.erase(nums[i]);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int, int> mp;
        
        solve(nums, curr, ans, n, mp);
        return ans;
    }
};