class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == ')' && st.empty())
            {
                s[i] = '.';
            }
            else if(s[i] == ')'){
                st.pop();
            }
            else if(s[i] == '(')
                st.push(i);
        }
        
        
        while(!st.empty()){
            int x = st.top();
            s[x]= '.';
            st.pop();
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(s[i] != '.')
                ans += s[i];
        }
        return ans;
    }
};