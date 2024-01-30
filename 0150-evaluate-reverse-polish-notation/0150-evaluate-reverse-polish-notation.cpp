class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        int n = tokens.size();
        
        for(int i=0;i<n;i++)
        {
            if(isdigit(tokens[i][tokens[i].length() - 1]))
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();
                
                if(tokens[i][0] == '+')
                {
                    st.push(a+b);
                }
                else if(tokens[i][0] == '-')
                {
                    st.push(a-b);
                }
                else if(tokens[i][0] == '*')
                {
                    st.push(a*b);
                }
                else 
                {
                    if(a*b < 0)
                        st.push(ceil(a/b));
                    else
                        st.push(floor(a/b));
                }
            }
        }
        return st.top();
    }
};