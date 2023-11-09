#define mod 1000000007

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length();
        int ans = 0;
        char c = s[0];
        
        for(int i=0;i<n;)
        {
            int count = 0;
            c = s[i];
            
            while(s[i] == c)
            {
                count++;
                ans = (ans%mod + count%mod)%mod;
                i++;
            }
        }
        
        return ans;
    }
};