class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        long long ans = 0;
        
        for(int i=1;i<n;i++)
        {
            if(s[i] != s[i-1])
            {
                ans += min(i, n-i);
            }
        }
        
        return ans;
    }
};