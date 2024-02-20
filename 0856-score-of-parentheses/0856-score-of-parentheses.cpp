class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int i = 0, prev = 0;
        stack<int> st;
        
        while(i<n)
        {
            if(s[i] == '('){
                st.push(prev);
                prev = 0;
            }
            else
            {
                prev = st.top() + max(2*prev, 1);
                st.pop();
            }
            i++;
        }
        
        return prev;
    }
};