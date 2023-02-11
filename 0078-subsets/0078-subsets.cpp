class Solution {
    void func(set<vector<int>>& st, vector<int>& nums, int n, vector<int>& curr)
    {
        sort(curr.begin(), curr.end());
        vector<int> c = curr;
        
        if(n < 0)
        {
           st.insert(curr);
           st.insert(c);
           return;   
        }
        
        st.insert(curr);
        st.insert(c);
        
        curr.push_back(nums[n]);
        
        func(st, nums, n-1, curr);
        func(st, nums, n-1, c);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        vector<int> curr;
        func(st, nums, n-1, curr);
        
        for(auto it: st)
        {
         ans.push_back(it);   
        }
        
        return ans;
    }
};