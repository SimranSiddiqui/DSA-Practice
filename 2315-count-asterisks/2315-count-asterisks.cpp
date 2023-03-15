class Solution {
public:
    int countAsterisks(string s) {
        stack<char> st;
        int n = s.length();
        int count =0 ;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                if(s[i] == '*')
                    count++;
                else if(s[i] == '|')
                    st.push(s[i]);
            }
            else if(s[i] == '|')
                st.pop();
        }
        
        return count;
    }
};