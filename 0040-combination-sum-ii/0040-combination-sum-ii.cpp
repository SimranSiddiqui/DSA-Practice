class Solution {
    void function(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& curr, int ind, int n)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            if(candidates[i] > target)
                break;
            if(i == ind || candidates[i] != candidates[i-1])
            {
                curr.push_back(candidates[i]);
                function(candidates, target-candidates[i], ans, curr, i+1,n);
                curr.pop_back();
                
            }
            else
                continue;
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        
        function(candidates, target, ans, curr, 0, n);
        
        return ans;
    }
};