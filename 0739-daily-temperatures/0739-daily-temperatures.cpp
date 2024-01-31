class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> nsr(n, 0);     
        stack<pair<int, int>> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first <= temp[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push({temp[i], i});
                nsr[i] = 0;
            }
            else
            {
                nsr[i] = st.top().second;
                st.push({temp[i], i});
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nsr[i] != 0)
            {
                nsr[i] = nsr[i] - i;
            }
        }
        
        return nsr;
    }
};