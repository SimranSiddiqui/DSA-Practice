class Solution {
    
    void change(vector<vector<int>> &ans, int n)
    {
        for(auto &it: ans)
        {
            vector<int> x;
            
            for(int i=1,j=0;i<=n;)
            {
                if(j >= it.size())
                {
                    x.push_back(i);
                    i++;
                }
                else if(i == it[j])
                {
                    i++;
                    j++;
                }
                else if(i < it[j])
                {
                    x.push_back(i);
                    i++;
                }
            }
            
            it = x;
        }
        
        return;
    }
    
    void solve(int n, int k, int i, vector<int> curr, vector<vector<int>> &ans)
    {
        if(curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }
        if(i > n)
            return;
        
        curr.push_back(i);
        solve(n, k, i+1, curr, ans);
        curr.pop_back();
        solve(n, k, i+1, curr, ans);
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        //set<vector<int>> ans;
        vector<int> curr;
        vector<vector<int>> ans;
        
        if(k <= n/2 || n==k)
        solve(n, k, 1, curr, ans);
        else
        solve(n, n-k, 1, curr, ans);
        
        if(k > n/2 && n!=k)
        change(ans, n);
        
        return ans;
    }
};