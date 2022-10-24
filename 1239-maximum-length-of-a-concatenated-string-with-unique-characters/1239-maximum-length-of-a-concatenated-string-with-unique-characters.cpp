class Solution
{
public:
    int ans = 0;
    bool isUnique(string s)
    {
        set<char> st(s.begin(), s.end());
        return (st.size() == s.length());
    }
    void solve(int index, string s, vector<string> &arr)
    {
        if (!isUnique(s))
            return;
        ans = max(ans, (int)s.length());
        for (int i = index; i < arr.size(); i++)
        {
            solve(i + 1, s + arr[i], arr);
        }
    }
    int maxLength(vector<string> &arr)
    {
        solve(0, "", arr);
        return ans;
    }
};