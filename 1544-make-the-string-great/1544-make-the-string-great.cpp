class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty() || tolower(s[i]) != tolower(st.top()) || st.top() == s[i])
                st.push(s[i]);
            else
            {
                st.pop();
            }
        }
        
        int m = st.size();
        string ans(m, '.');
        while(!st.empty())
        {
            ans[m-1] = st.top();
            m--;
            st.pop();
        }
        
        return ans;
    }
};