class Solution {
    
    void solve(vector<int> &nums, vector<int> &curr, set<vector<int>> &st, int n, unordered_map<int, int> &mp)
    {
        if(curr.size() == n)
        {
            st.insert(curr);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(i) == mp.end())
            {
                mp[i]++;
                curr.push_back(nums[i]);
                
                solve(nums, curr, st, n, mp);
                
                mp.erase(i);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int, int> mp;
        set<vector<int>> st;
        
        solve(nums, curr, st, n, mp);
        for(auto it: st)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};