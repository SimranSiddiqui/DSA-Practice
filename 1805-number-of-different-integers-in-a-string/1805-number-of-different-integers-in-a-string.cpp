class Solution {
public:
    int numDifferentIntegers(string s) {
        unordered_set<string> st;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                while(i<n && s[i] == '0')
                    i++;
                
                string x = "";
                while(i<n && isdigit(s[i]))
                {
                     x += s[i];
                     i++;
                }
                
                if(x.length() > 0)
                st.insert(x);
                else
                st.insert("0");
            }
        }
        
        return st.size();
    }
};