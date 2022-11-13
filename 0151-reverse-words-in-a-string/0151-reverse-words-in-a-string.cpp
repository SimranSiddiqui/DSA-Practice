class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<string> st;
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
            while(s[i]==' ')
            {
                i++;
            }
            string x = "";
            while(i<n && s[i] != ' ')
            {
                x += s[i];
                i++;
            }
            if(x.size()>0)
            st.push(x);
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
            if(!st.empty())
                ans += ' ';
        }
        
        return ans;
    }
};