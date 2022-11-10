class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        stack<int> count;
        
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                count.push(1);
                if(count.top() == k)
                {
                    count.pop();
                    for(int i=0;i<k;i++)
                    {
                        st.pop();
                    }
                }
            }
            else if(s[i] == st.top())
            {
                int x = count.top();
                count.pop();
                x++;
                count.push(x);
                
                st.push(s[i]);
                
                if(count.top() == k)
                {
                    count.pop();
                    for(int i=0;i<k;i++)
                    {
                        st.pop();
                    }
                }
            }
            else
            {
                st.push(s[i]);
                count.push(1);
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};