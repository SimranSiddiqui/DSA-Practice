class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int ans = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i=0, j=0;
        while(i<n)
        {
            if(j >= m)
                break;
            if(g[i] <= s[j])
            {
                ans++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        
        return ans;
    }
};