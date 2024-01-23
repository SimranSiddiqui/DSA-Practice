class Solution
{
public:
    int ans = 0;
    bool isUnique(string s)
    {
        set<char> st(s.begin(), s.end());
        return (st.size() == s.length());
    }
    
    void solve(int n, string s, vector<string> &arr)
    {
        if(n < 0)
        {
            int len = s.length();
            if(isUnique(s))
                ans = max(ans, len);
            return;
        }
        
        if(!isUnique(s))
            return;
        
        solve(n-1, s + arr[n], arr);
        solve(n-1, s, arr);
    }
    
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        solve(n-1, "", arr);
        return ans;
    }
};