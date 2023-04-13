class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i =0, j =0;
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(pushed[i]);
            
            while(!st.empty() && st.top() == popped[j])
            {
                j++;
                st.pop();
            }
        }
        
        while(j < n)
        {
            if(!st.empty() && popped[j] == st.top())
            {
                st.pop();
                j++;
            }
            else
                break;
        }
        
        if(st.empty())
            return true;
        else
            return false;
    }
};