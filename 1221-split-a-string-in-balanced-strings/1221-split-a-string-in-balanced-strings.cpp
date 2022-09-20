class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> st;
        
        int n = s.length();
        int count =0;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                st.push(s[i]);
            
            else
            {
                if(s[i] == st.top())
                    st.push(s[i]);
                else 
                    st.pop();
            }
            
            if(st.empty())
                count++;
        }
        
        return count;
    }
};