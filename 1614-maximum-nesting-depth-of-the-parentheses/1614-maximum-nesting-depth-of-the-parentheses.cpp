class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char> st;
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                st.pop();
            }
            
           
            int curr = st.size();
            ans = max(ans,curr);
        }
        
        return ans;
    }
};