class Solution {
    void calSum(vector<int> &candidates, int target, int &sum, int n, set<vector<int>> &st, vector<int> &x)
    {
        if(n < 0)
        {
            if(sum == target)
                st.insert(x);
            
            return ;
        }
        
        if(sum >= target)
        {
            if(sum == target)
            st.insert(x);
            return;
        }
        
        int s1 = sum + candidates[n];
        vector<int> v1 = x;
        v1.push_back(candidates[n]);
        
        calSum(candidates, target, s1, n-1, st, v1);
        calSum(candidates, target, s1, n, st, v1);
        calSum(candidates, target, sum, n-1, st, x);
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        int sum =0;
        vector<int> x;
        set<vector<int>> st;
        
        calSum(candidates, target, sum, n-1, st, x);
        
        for(auto it: st)
            ans.push_back(it);
        
        return ans;
    }
};