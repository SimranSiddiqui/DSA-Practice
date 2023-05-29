class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> disLeft, disRight(n, 0);
        
        unordered_set<char> st;
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
            disLeft.push_back(st.size());
        }
        
        st.clear();
        for(int i=n-1;i>=0;i--)
        {
            disRight[i] = st.size();
            st.insert(s[i]);
        }
        
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(disRight[i] == disLeft[i])
                ans++;
        }
        
        return ans;
    }
};