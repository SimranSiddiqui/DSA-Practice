class Solution {
    
    void function(vector<int>& candidates, int target, int i, int n, vector<int>& curr, vector<vector<int>>& ans, int sum)
    {
        if(i >= n)
        {
            if(sum == target)
            {
                ans.push_back(curr);
                return;
            }
            return;
        }
        
        curr.push_back(candidates[i]);
        sum += candidates[i];
        if(sum <= target)
        function(candidates, target, i, n, curr, ans, sum);   // Including the element
        
        curr.pop_back();
        sum -= candidates[i];
        function(candidates, target, i+1, n, curr, ans, sum);
        
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        
        vector<int> curr;
        function(candidates, target, 0, n, curr, ans, 0);
        
        return ans;
    }
};